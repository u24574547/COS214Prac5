#include <cstdint>
#include <iomanip>
#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "Customer.h"
#include "FloweringSupplier.h"
#include "Inventory.h"
#include "MossExpert.h"

void setBufferedInput(bool enable) {
    static bool enabled = true;
    static struct termios oldt;
    struct termios newt;

    if (enable && !enabled) {
        // restore terminal settings
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        enabled = true;
    } else if (!enable && enabled) {
        // disable canonical mode and echo
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        enabled = false;
    }
}

void customerMenu(std::vector<Customer*>& customers, Customer* customer) {
    std::string menu =  "Customer actions:\n"
    "1. Plant Inquiry\n"
    "2. Order a Plant\n"
    "3. Refund\n"
    "4. View Customer details\n"
    "5. View Customer transaction history\n"
    "b to return to customer selection menu\n";
    char c;
    while (true) {
        c = getchar();
        if (c == '1') ;
        else if (c == 's') std::cout << "Down\n";
        else if (c == 'a') std::cout << "Left\n";
        else if (c == 'd') std::cout << "Right\n";
        else if (c == 'b') break;
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
    "b to return to customer selection menu\n";
    std::cout<<menu<<std::endl;
    char c;
    while (true) {
        c = getchar();
        if (c == '1') {
            Customer* customer = chooseCustomer(customers);
            if (customer!=nullptr) {
                customerMenu(customers, customer);
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

int main() {
    Supplier* supp = new FloweringSupplier();
    Inventory* inv = new Inventory();
    Employee* employee = new MossExpert("John Employee",inv);
    std::vector<Customer*> customers = vector<Customer*>();
    std::string menu =  "Choose an action type:\n"
    "1. Customer\n"
    "2. Plant\n"
    "3. Employee\n"
    "4. Inventory\n"
    "n to end the day\n"
    "q to quit the simulation\n";
    std::cout<<menu<<std::endl;
    char c;
    setBufferedInput(false);
    while (true) {
        c = getchar();
        if (c == '1') customerSelectionMenu(customers, employee);
        else if (c == 's') std::cout << "Down\n";
        else if (c == 'a') std::cout << "Left\n";
        else if (c == 'd') std::cout << "Right\n";
        else if (c == 'q') break;
        std::cout<<menu<<std::endl;
    }

    setBufferedInput(true);

    delete supp;
    delete inv;
    return 0;
}
