#include <cstdint>
#include <iomanip>
#include <iostream>
#include <random>
#include <termios.h>
#include <unistd.h>

#include "Customer.h"
#include "Day.h"
#include "FernExpert.h"
#include "FernSupplier.h"
#include "FloweringExpert.h"
#include "FloweringSupplier.h"
#include "Gardener.h"
#include "Inventory.h"
#include "MatureState.h"
#include "MossExpert.h"
#include "MossSupplier.h"
#include "NonFloweringSupplier.h"
#include "ReadyForSale.h"

const std::string reset  = "\033[0m";
const std::string red    = "\033[31m";
const std::string green  = "\033[32m";
const std::string yellow = "\033[33m";
const std::string blue   = "\033[34m";
const std::string bold   = "\033[1m";

void setBufferedInput(bool enable) {
    static bool enabled = true;
    static struct termios oldt;
    struct termios newt;

    auto purge_stdio_buffer = []() {
        // Try to consume any bytes already in the C++ stream buffer
        std::cin.clear(); // clear errors if any
        std::streamsize avail = std::cin.rdbuf()->in_avail();
        while (avail-- > 0) {
            // withdraw characters without blocking
            int ch = std::cin.get();
            if (ch == EOF) break;
        }
    };

    auto reopen_stdin_from_tty = []() -> bool {
        // Reopen stdin from /dev/tty to reset stdio buffering.
        // Returns true if succeeded.
        if (!isatty(STDIN_FILENO)) return false; // not a TTY (can't reopen)
        FILE *f = freopen("/dev/tty", "r", stdin);
        if (f == nullptr) return false;
        // After freopen, also clear C++ iostream association
        std::cin.clear();
        return true;
    };

    auto purge_kernel_queue = []() {
        if (isatty(STDIN_FILENO)) tcflush(STDIN_FILENO, TCIFLUSH);
    };

    if (enable && !enabled) {
        // Going back to buffered (canonical) mode:
        // First, purge any stray input so the buffered-mode code starts clean.
        // Reopen stdin from /dev/tty if possible (this drops stdio buffers).
        if (!reopen_stdin_from_tty()) {
            // fallback: try draining stdio buffer
            purge_stdio_buffer();
        }
        purge_kernel_queue();

        // restore saved termios
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        enabled = true;
    }
    else if (!enable && enabled) {
        // Going into unbuffered (non-canonical) mode:
        // Purge both stdio buffers and kernel queue BEFORE switching modes.
        if (!reopen_stdin_from_tty()) {
            purge_stdio_buffer();
        }
        purge_kernel_queue();

        // Save current terminal attributes and disable canonical mode + echo.
        if (tcgetattr(STDIN_FILENO, &oldt) == -1) {
            // if tcgetattr fails, bail out silently (you can handle error if desired)
            return;
        }
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        newt.c_cc[VMIN]  = 1; // return after 1 byte
        newt.c_cc[VTIME] = 0; // no timeout
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        enabled = false;
    }
}

void plantInquiry(Customer * customer) {
    setBufferedInput(true);
    while (true) {
        std::cout<<"Enter plant type to enquire about(Fern/Flowering/Nonflowering/Moss):";
        std::string type;
        std::cin>>type;
        if (type == "Fern" || type == "Flowering" || type == "Nonflowering" || type == "Moss") {
            customer->inquiry(type);
            break;
        }
        else {
            std::cout<<"Invalid plant type. Please retry"<<std::endl;
        }
    }
    setBufferedInput(false);
}

void orderPlant(Customer * customer) {
    setBufferedInput(true);
    while (true) {
        std::cout<<"Enter plant species to order:";
        std::string species;
        std::cin>>species;
        customer->order(species);
        std::cout<<"Order another plant?(Y/N):";
        std::cin>>species;
        if (species == "N") {
            break;
        }
    }
    setBufferedInput(false);
}

void customerMenu(Customer* customer) {
    std::string menu =  "Customer actions:\n"
    "1. Plant Inquiry\n"
    "2. Order a Plant\n"
    "3. Refund\n"
    "4. View Customer details\n"
    "5. View Customer transaction history\n"
    "b to return to customer selection menu\n";
    std::cout<<menu<<std::endl;
    char c;
    while (true) {
        c = getchar();
        if (c=='1') plantInquiry(customer);
        else if (c == '2') orderPlant(customer);
        else if (c == '3') customer->refund();
        else if (c == '4') std::cout<<customer->toString()<<std::endl;
        else if (c == '5') std::cout<<customer->transactionHistoryToString()<<std::endl;
        else if (c == 'b') break;
        else std::cout << "Not implemented yet\n";
        std::cout<<menu<<std::endl;
    }
}

Customer *chooseCustomer(vector<Customer *> &customers) {
    Customer* customer=nullptr;
    setBufferedInput(true);
    bool done = false;
    while (!done) {
        if (!customers.empty()) {
            for (auto it = customers.begin(); it != customers.end(); ++it) {
                std::cout<<(*it)->toString()<<std::endl;
            }
            std::cout<<"Enter the ID of the customer or c to cancel:";
            std::string id;
            std::cin>>id;
            if (id=="c") done=true;
            for (auto it = customers.begin(); it != customers.end(); ++it) {
                if (id==(*it)->getId()) {
                    customer=*it;
                    done=true;
                    break;
                }
            }
        }else {
            std::cout<<"No customers exist.\n"<<std::endl;
            done=true;
        }
    }
    setBufferedInput(false);
    return customer;
}

std::pair<std::string, bool> incrementHex6(const std::string &in) {
    if (in.size() != 6) {
        throw std::invalid_argument("Input must be exactly 6 hex digits.");
    }

    uint32_t value = 0;
    for (char c : in) {
        value <<= 4;
        if (c >= '0' && c <= '9') {
            value |= (uint32_t)(c - '0');
        } else if (c >= 'A' && c <= 'F') {
            value |= (uint32_t)(c - 'A' + 10);
        } else if (c >= 'a' && c <= 'f') {
            value |= (uint32_t)(c - 'a' + 10);
        } else {
            throw std::invalid_argument("Invalid hex digit in input.");
        }
    }

    bool wrapped = false;
    if (value == 0xFFFFFFu) {
        value = 0;
        wrapped = true;
    } else {
        ++value;
    }

    std::ostringstream oss;
    oss << std::uppercase << std::hex << std::setw(6) << std::setfill('0') << value;
    return std::make_pair(oss.str(), wrapped);
}

void createCustomer(vector<Customer *> &customers, Employee *employee) {
    setBufferedInput(true);
    std::cout << "Enter new customers name:";
    std::string name;
    std::cin >> name;
    Customer* customer=nullptr;
    if (customers.empty()) {
        customer=new Customer(name, employee, "000000");
    }
    else {
        std::pair<std::string, bool> id=incrementHex6(customers.back()->getId());
        if (id.second) {
            std::cout << "Maximum customers reached. No more can be added.";
        }
        else {
            customer=new Customer(name, employee, id.first);
        }
    }
    customers.push_back(customer);
    setBufferedInput(false);
}

void customerSelectionMenu(vector<Customer *>& customers, Employee* employee) {
    std::string menu =  "Choose/Create Customer:\n"
    "1. Choose a customer\n"
    "2. Create a new customer\n"
    "b to return to main menu\n";
    std::cout<<menu<<std::endl;
    char c;
    while (true) {
        c = getchar();
        if (c == '1') {
            Customer* customer = chooseCustomer(customers);
            if (customer!=nullptr) {
                customerMenu(customer);
                break;
            }
        }
        else if (c == '2') {
            createCustomer(customers, employee);
        }
        else if (c == 'b') break;
        std::cout<<menu<<std::endl;
    }
}

void movePlant(Plant * plant) {
    int plantType;
    while (true) {
        std::cout<<"Enter plant's storage location(Greenhouse/Shadenet/Semi-shaded/Sunny):";
        std::string type;
        std::cin>>type;
        if (type == "Greenhouse") {
            plantType=1;
            break;
        }
        if (type == "Shadenet") {
            plantType=2;
            break;
        }
        if (type == "Semi-shaded") {
            plantType=3;
            break;
        }
        if (type == "Sunny") {
            plantType=4;
            break;
        }
        std::cout<<"Invalid environment type. Please retry"<<std::endl;
    }
    plant->setCurrentEnvironment(plantType);
}

void plantMenu(Plant* plant) {
    std::string menu =  "Customer actions:\n"
    "1. View plant details\n"
    "2. Move Plant\n"
    "3. Water plant\n"
    "b to return to customer selection menu\n";
    std::cout<<menu<<std::endl;
    char c;
    while (true) {
        c = getchar();
        if (c=='1') std::cout<<plant->toString()<<std::endl;
        else if (c == '2') movePlant(plant);
        else if (c == '3') {
            plant->water(200);
            std::cout<<"Plant watered!"<<std::endl;
        }
        else if (c == 'b') break;
        else std::cout << "Not implemented yet\n";
        std::cout<<menu<<std::endl;
    }
}

bool tryParseDouble(const std::string& str, double& outValue) {
    try {
        size_t pos;
        outValue = std::stod(str, &pos);
        return pos == str.size();
    } catch (...) {
        return false;
    }
}

void createPlant(Inventory * inv) {
    setBufferedInput(true);
    int plantType;
    while (true) {
        std::cout<<"Enter plant type to create(Fern/Flowering/Nonflowering/Moss):";
        std::string type;
        std::cin>>type;
        if (type == "Fern") {
            plantType=1;
            break;
        }
        if (type == "Flowering") {
            plantType=2;
            break;
        }
        if (type == "Nonflowering") {
            plantType=3;
            break;
        }
        if (type == "Moss") {
            plantType=4;
            break;
        }
        std::cout<<"Invalid plant type. Please retry"<<std::endl;
    }

    std::cout << "Enter new plants species:";
    std::string name;
    std::cin >> name;
    Supplier* supp;
    switch (plantType) {
        case 1:
            supp=new FernSupplier();
            break;
        case 2:
            supp=new FloweringSupplier();
            break;
        case 3:
            supp=new NonFloweringSupplier();
            break;
        case 4:
            supp=new MossSupplier();
            break;
        default:
            throw std::invalid_argument("Invalid plant type.");
    }
    supp->setSpecies(name);

    //set state and growthLevel
    while (true) {
        std::cout<<"Enter 0 for default.\nWhat stage in its lifecycle is the plant(Unplanted/Seedling/Mature/ReadyForSale):";
        std::string type;
        std::cin>>type;
        if (type == "Unplanted" || type=="0") {
            plantType=1;
            break;
        }
        if (type == "Seedling") {
            plantType=2;
            break;
        }
        if (type == "Mature") {
            plantType=3;
            break;
        }
        if (type == "ReadyForSale") {
            plantType=4;
            break;
        }
        std::cout<<"Invalid lifecycle stage. Please retry"<<std::endl;
    }

    std::random_device rd;         // seeds the generator (non-deterministic)
    std::mt19937 gen(rd());        // Mersenne Twister RNG

    // Define the range (e.g. 1 to 100)
    uniform_int_distribution<> dist;
    switch (plantType) {
        case 1://Unplanted
            supp->setState(new UnplantedState());
            supp->setGrowthLevel(0);
            break;
        case 2://Seedling
            supp->setState(new SeedlingState());
            dist=uniform_int_distribution<>(0, 20);
            supp->setGrowthLevel(dist(gen));
            break;
        case 3://Mature
            supp->setState(new MatureState());
            dist=uniform_int_distribution<>(20, 50);
            supp->setGrowthLevel(dist(gen));
            break;
        case 4://ReadyForSale
            supp->setState(new ReadyForSaleState());
            dist=uniform_int_distribution<>(50, 200);
            supp->setGrowthLevel(dist(gen));
            break;
        default:
            throw std::invalid_argument("Invalid plant state.");
    }

    //growth rate
    while (true) {
        std::cout<<"Enter 0 for default.\nHow fast does the plant grow(1.0-6.0):";
        std::string type;
        std::cin>>type;
        double value;
        if (type=="0") {
            supp->setGrowthRate(3.0);
            break;
        }
        if (tryParseDouble(type, value) && value>=1.0 && value<=6.0) {
            supp->setGrowthRate(value);
            break;
        }
        std::cout<<"Invalid growth rate. Please retry"<<std::endl;
    }

    //preferred environment
    while (true) {
        std::cout<<"Enter plant's preferred environment(Tropical/Temperate/Continental/Dry):";
        std::string type;
        std::cin>>type;
        if (type == "Tropical") {
            plantType=1;
            break;
        }
        if (type == "Temperate") {
            plantType=2;
            break;
        }
        if (type == "Continental") {
            plantType=3;
            break;
        }
        if (type == "Dry") {
            plantType=4;
            break;
        }
        std::cout<<"Invalid environment type. Please retry"<<std::endl;
    }
    supp->setPreferredEnvironment(plantType);

    //current environment
    while (true) {
        std::cout<<"Enter plant's storage location(Greenhouse/Shadenet/Semi-shaded/Sunny):";
        std::string type;
        std::cin>>type;
        if (type == "Greenhouse") {
            plantType=1;
            break;
        }
        if (type == "Shadenet") {
            plantType=2;
            break;
        }
        if (type == "Semi-shaded") {
            plantType=3;
            break;
        }
        if (type == "Sunny") {
            plantType=4;
            break;
        }
        std::cout<<"Invalid environment type. Please retry"<<std::endl;
    }
    supp->setCurrentEnvironment(plantType);

    inv->addPlant(supp->getPlant());
    setBufferedInput(false);
}

bool tryParseInt(const std::string& str, int& outValue) {
    try {
        size_t pos;
        outValue = std::stoi(str, &pos);   // attempt to parse
        return pos == str.size();          // ensure whole string was parsed
    } catch (...) {
        return false;                      // invalid argument or out of range
    }
}

Plant * choosePlant(Inventory * inv) {
    Plant* plant=nullptr;
    Iterator<Plant*>* iter = inv->createIterator();
    setBufferedInput(true);
    bool done = false;
    while (!done) {
        if (!iter->isDone()) {
            //output plants
            int counter=1;
            while (!iter->isDone()) {
                std::cout<<"=============="<<counter<<"=============="<<std::endl;
                std::cout<<iter->next()->toString()<<std::endl;
                counter++;
            }
            //choose plant
            std::cout<<"Enter the number of the plant or c to cancel:";
            std::string id;
            std::cin>>id;
            if (id=="c") {
                done=true;
            }
            else {//fetch plant pointer
                iter->first();
                int value;
                if (tryParseInt(id, value)) {
                    for (int i=0;i<value-1;i++) {
                        iter->next();
                    }
                    plant=iter->current();
                    done=true;
                } else {
                    std::cout << "Invalid input.\n";
                }
            }
        }else {
            std::cout<<"No plants are in stock.\n"<<std::endl;
            done=true;
        }
    }
    setBufferedInput(false);
    return plant;
}

void plantSelectionMenu(Inventory* inv) {
    std::string menu =  "Choose/Create Plant:\n"
    "1. Choose a plant\n"
    "2. Create a new plant\n"
    "b to return to main menu\n";
    std::cout<<menu<<std::endl;
    char c;
    while (true) {
        c = getchar();
        if (c == '1') {
            Plant* plant = choosePlant(inv);
            if (plant!=nullptr) {
                plantMenu(plant);
                break;
            }
        }
        else if (c == '2') {
            createPlant(inv);
        }
        else if (c == 'b') break;
        std::cout<<menu<<std::endl;
    }
}

void makeSeeds(vector<Plant *>& plants, Supplier **suppliers, int n, int supplier, double price, std::string species, int requiredWaterPerDay, double growthRate, int prefferedEnvironment) {
    suppliers[supplier]->setPrice(price);
    suppliers[supplier]->setSpecies(species);
    suppliers[supplier]->setRequiredWaterPerDay(requiredWaterPerDay);
    suppliers[supplier]->setGrowthRate(2*growthRate);
    suppliers[supplier]->setPreferredEnvironment(prefferedEnvironment);
    int divisor = n/4;
    for (int i=0;i<n;i++) {
        suppliers[supplier]->setCurrentEnvironment(1+i/divisor);
        plants.push_back(suppliers[supplier]->getPlant());
    }
}

vector<Plant *> getStartingPlants() {
    vector<Plant *> plants;
    /*
     *===Gift Bundle===
     * Tulipa gesneriana - flowering done
     * Rosa chinensis - flowering done
     * Nephrolepis exaltata - fern done
     *
     * ===FrostReady Bundle===
     * Riccia fluitans - nonflowering done
     * Nephrolepis exaltata - fern done
     * Bryum argenteum - moss done
     *
     * ===Terrarium Bundle===
     * Bryum argenteum - moss done
     * Adiantum raddianum - fern done
     * Fittonia albivenis - flowering
     *
     * environments(1-4): Tropical/Temperate/Continental/Dry
     */
    Supplier** suppliers = new Supplier*[4];
    suppliers[0]=new FernSupplier();
    suppliers[1]=new FloweringSupplier();
    suppliers[2]=new MossSupplier();
    suppliers[3]=new NonFloweringSupplier();

    //Tulipa gesneriana - flowering
    double price=100.0;
    std::string species="Tulipa gesneriana";
    int requiredWaterPerDay=32;
    double growthRate=0.9;
    int preferredEnvironment=2;

    makeSeeds(plants, suppliers, 12, 1, price, species, requiredWaterPerDay, growthRate, preferredEnvironment);

    //Rosa chinensis - flowering
    price=165.0;
    species="Rosa chinensis";
    requiredWaterPerDay=93;
    growthRate=1.1;
    preferredEnvironment=2;

    makeSeeds(plants, suppliers, 12, 1, price, species, requiredWaterPerDay, growthRate, preferredEnvironment);

    //Nephrolepis exaltata - fern
    price=120.0;
    species="Nephrolepis exaltata";
    requiredWaterPerDay=121;
    growthRate=1.2;
    preferredEnvironment=1;

    makeSeeds(plants, suppliers, 24, 0, price, species, requiredWaterPerDay, growthRate, preferredEnvironment);

    //Riccia fluitans - aquatic non flowering
    price=85.0;
    species="Riccia fluitans";
    requiredWaterPerDay=500;
    growthRate=1.3;
    preferredEnvironment=1;

    makeSeeds(plants, suppliers, 12, 3, price, species, requiredWaterPerDay, growthRate, preferredEnvironment);

    //Bryum argenteum - moss
    price=65.0;
    species="Bryum argenteum";
    requiredWaterPerDay=10;
    growthRate=1.0;
    preferredEnvironment=3;

    makeSeeds(plants, suppliers, 24, 2, price, species, requiredWaterPerDay, growthRate, preferredEnvironment);

    //Adiantum raddianum - fern
    price=130.0;
    species="Adiantum raddianum";
    requiredWaterPerDay=121;
    growthRate=1.1;
    preferredEnvironment=1;

    makeSeeds(plants, suppliers, 12, 0, price, species, requiredWaterPerDay, growthRate, preferredEnvironment);

    //Fittonia albivenis - non flowering
    price=115.0;
    species="Fittonia albivenis";
    requiredWaterPerDay=125;
    growthRate=1.05;
    preferredEnvironment=1;

    makeSeeds(plants, suppliers, 12, 3, price, species, requiredWaterPerDay, growthRate, preferredEnvironment);
    for (int i=0; i<4;i++) {
        delete suppliers[i];
    }
    delete[] suppliers;
    return plants;
}

void employeeMenu(Employee * employee) {
    std::string menu =  "Options:\n"
    "1. View employee details\n"
    "2. Hire a new employee\n"
    "b to return to main menu\n";
    std::cout<<menu<<std::endl;
    char c;
    while (true) {
        c = getchar();
        if (c == '1') {
            cout<<employee->toString()<<"\n"<<endl;
        }
        else if (c == '2') {
            cout<<"Not implemented yet";
        }
        else if (c == 'b') break;
        std::cout<<menu<<std::endl;
    }
}

void autoWatering(Employee * employee) {
    // Iterator<Plant*>* iter = inv->createIterator();
    // Plant* curr;
    // while ((curr=iter->next())!=nullptr) {
    //     employee
    // }
    employee->handleWater(1);
    cout<<endl;
    employee->handleWater(2);
    cout<<endl;
    employee->handleWater(3);
    cout<<endl;
    employee->handleWater(4);
}

int main() {
    Day* day = new Day();
    Inventory* inv = new Inventory(getStartingPlants());
    inv->observeTime(day);
    Employee* employee = new MossExpert("John Mossman",inv);
    Employee* gardener = new Gardener("Sound Gardener", inv);
    employee->setNext(gardener);

    Employee* ferb = new FernExpert("Ferb Ferman", inv);
    gardener->setNext(ferb);

    Employee* rose = new FloweringExpert("Rose Knower", inv);
    ferb->setNext(rose);
    std::vector<Customer*> customers = vector<Customer*>();

    std::string menu =  "Choose an action type:\n"
    "1. Customer\n"
    "2. Plant\n"
    "3. Employee\n"
    "4. Toggle automatic management\n"
    "n to end the day\n"
    "q to quit the simulation\n";
    std::cout<<menu<<std::endl;
    char c;
    bool autoManagementEnabled = false;
    int dayNumber = 1;
    setBufferedInput(false);
    while (true) {
        c = getchar();
        if (c == '1') customerSelectionMenu(customers, employee);
        else if (c == '2') plantSelectionMenu(inv);
        else if (c == '3') employeeMenu(employee);
        else if (c == '4') {
            autoManagementEnabled=!autoManagementEnabled;
            cout<<"Auto Management "<<(autoManagementEnabled?"Enabled":"Disabled")<<endl;
        }
        else if (c == 'n') {
            dayNumber++;
            if (autoManagementEnabled) autoWatering(employee);
            day->notify();
            cout<<endl;
        }
        else if (c == 'q') break;
        else std::cout<<"Invalid input."<<std::endl;
        std::cout<<"Day: "<<dayNumber<<"\t"<<menu<<std::endl;
    }

    setBufferedInput(true);

    delete inv;
    return 0;
}
