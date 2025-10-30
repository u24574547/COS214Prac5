// #include "TransactionHistory.h"
// #include "Command.h"
// #include "OrderCommand.h"
// #include "RefundCommand.h"
// #include "InquiryCommand.h"
// #include "Customer.h"
// #include "Employee.h"
// #include "FernExpert.h"
// #include "Fern.h"
// #include "Moss.h"
// #include "Flowering.h"
// #include "PlantState.h"
// #include "UnplantedState.h"

// void testInventory() {
//     Inventory* inv = new Inventory(); 

//     PlantState* state = new UnplantedState(); 
//     Plant* fern = new Fern("Ferb", 2, 0, false, 1.0, 2, state);
//     Plant* moss = new Moss("Boss", 2, 0, false, 1.0, 2, state);
//     Plant* flowrering = new Flowering("Bowring", 2, 0, false, 1.0, 2, state);
    
//     std::cout << "==============ADDING PLANTS TO INVENTORY=================\n";
//     inv->addPlant(fern);
//     inv->addPlant(moss);
//     inv->addPlant(flowrering);

//     std::cout << std::endl;
//     std::cout << "==============ITERATING THROUGH INVENTORY=================\n";  

//     Iterator<Plant*>* it = inv->createIterator();
//     for (it->first(); !it->isDone(); it->next()) {
//         std::cout << "Plant species: " <<
//         it->current()->getSpecies() << std::endl;
//     }

//     std::cout << std::endl;
//     std::cout << "==============REMOVING PLANT(S)=================\n"; 
    
//     std::cout << "Removed " << inv->getPlant("Boss")->getSpecies() << "\n";
    
//     std::cout << std::endl;
//     std::cout << "==============ITERATING THROUGH INVENTORY=================\n"; 
//     for (it->first(); !it->isDone(); it->next()) {
//         std::cout << "Plant species: " <<
//         it->current()->getSpecies() << std::endl;
//     }

// }

// void testTransasctions() {
//     TransactionHistory* history = new TransactionHistory();
//     Inventory* inv = new Inventory();  

    
//     PlantState* state = new UnplantedState(); 
//     Plant* fern = new Fern("Ferb", 2, 0, false, 1.0, 2, state);
//     Plant* moss = new Moss("Boss", 2, 0, false, 1.0, 2, state);
//     inv->addPlant(fern);
//     inv->addPlant(moss);

//     Employee* mediator = new FernExpert("Jerry", inv);

//     Customer* frank = new Customer("Frank", mediator, "123");
//     Customer* manny = new Customer("Manny", mediator, "456");

//     //create dummy commands
//     Command* order = new OrderCommand(frank, mediator, "Moss");
//     Command* anotherOrder = new OrderCommand(manny, mediator, "Fern");

//     //add orders
//     std::cout << "==============ADDING ORDERS=================\n"; 
//     history->addOrder(order);
//     history->addOrder(anotherOrder);
//     std::cout << std::endl;

//     std::cout << "==============TRAVERSING THROUGH ORDERS=================\n"; 
//     Iterator<Command*>* iterator = history->createIterator();
//     for (iterator->first(); !iterator->isDone(); iterator->next()) {
//         std::cout << "Transaction from: " << iterator->current()->getCustomer()->getName() << "\n";
//     }
//     std::cout << "==============CAPTURING ORDER STATE=================\n"; 
//     TransactionMemento* mem = history->captureState();
//     std::vector<Command*> transactions = mem->getTransactions();

//     for (auto it = transactions.begin(); it!= transactions.end(); it++) {
//         std::cout << "Transaction from:" << (*it)->getCustomer()->getName() << '\n';
//     }
//     std::cout << std::endl;

//     std::cout << "==============REMOVING ORDERS=================\n"; 
//     history->removeOrder(order);

//     std::cout << std::endl;
//     std::cout << "==============TRAVERSING THROUGH ORDERS=================\n"; 

//     for (iterator->first(); !iterator->isDone(); iterator->next()) {
//         std::cout << "Transaction from: " << iterator->current()->getCustomer()->getName() << "\n";
//     }

//     std::cout << std::endl;

//     delete order;
//     delete anotherOrder;
//     delete frank;
//     delete manny;
//     delete state;
//     delete inv;
//     delete mediator;
//     delete history;

// }

// int main () {
//     // testInventory();
//     testTransasctions();
//     return 0;
// }

// Comment out or delete existing test functions

#include "TransactionHistory.h"
#include "Command.h"
#include "OrderCommand.h"
#include "RefundCommand.h"
#include "InquiryCommand.h"
#include "Customer.h"
#include "Employee.h"
#include "FernExpert.h"
#include "Fern.h"
#include "Moss.h"
#include "Flowering.h"
#include "PlantState.h"
#include "UnplantedState.h"
#include "Director.h"
#include "GiftBuilder.h"
#include "FrostReadyBuilder.h"
#include "TerrariumBuilder.h"
#include "FernSupplier.h"
#include "Fertiliser.h"
#include "FrostNet.h"

void testInventory() {
    std::cout << "\n=== Testing Inventory Management ===\n";
    
    Inventory* inv = new Inventory();
    PlantState* state = new UnplantedState();
    
    // Create test plants
    Plant* fern = new Fern("TestFern", 2, 0, false, 1.0, 2, state);
    Plant* moss = new Moss("TestMoss", 2, 0, false, 1.0, 2, state);
    Plant* flowering = new Flowering("TestFlower", 2, 0, false, 1.0, 2, state);
    
    std::cout << "Adding plants to inventory...\n";
    inv->addPlant(fern);
    inv->addPlant(moss);
    inv->addPlant(flowering);
    
    std::cout << "\nIterating through inventory:\n";
    Iterator<Plant*>* it = inv->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        std::cout << "- " << it->current()->getSpecies() << "\n";
    }
    
    std::cout << "\nRemoving TestMoss...\n";
    Plant* removed = inv->getPlant("TestMoss");
    if (removed) {
        std::cout << "Successfully removed: " << removed->getSpecies() << "\n";
        delete removed;
    }
    
    delete inv;
    delete it;
}

void testTransactions() {
    std::cout << "\n=== Testing Transaction System ===\n";
    
    Inventory* inv = new Inventory();
    Employee* mediator = new FernExpert("TestEmployee", inv);
    Customer* customer = new Customer("TestCustomer", mediator, "TEST001");
    
    // Add some plants to inventory
    inv->addPlant(new Fern("TestFern", 0, 0, false, 1.0, 0, new UnplantedState()));
    
    std::cout << "Testing order command...\n";
    customer->order("TestFern");
    
    std::cout << "\nTesting inquiry command...\n";
    customer->inquiry("Fern");
    
    delete customer;
    delete mediator;
    delete inv;
}

void testPlantLifecycle() {
    std::cout << "\n=== Testing Plant Lifecycle ===\n";
    
    Plant* plant = new Fern("LifecycleFern", 0, 0, false, 1.0, 0, new UnplantedState());
    
    std::cout << "Initial state: " << plant->getStateName() << "\n";
    
    for (int day = 1; day <= 5; ++day) {
        std::cout << "\nDay " << day << ":\n";
        plant->water();
        std::cout << "Watered - current state: " << plant->getStateName() << "\n";
        plant->endDay();
        std::cout << "After growth - state: " << plant->getStateName() 
                 << ", growth level: " << plant->getGrowthLevel() << "\n";
    }
    
    delete plant;
}

void testBuilderPattern() {
    std::cout << "\n=== Testing Builder Pattern ===\n";
    
    Inventory* inv = new Inventory();
    // Add plants for the builders to use
    inv->addPlant(new Fern("Fern", 0, 0, false, 1.0, 0, new UnplantedState()));
    inv->addPlant(new Flowering("Rose", 0, 0, false, 1.0, 0, new UnplantedState()));
    inv->addPlant(new Flowering("Tulip", 0, 0, false, 1.0, 0, new UnplantedState()));
    
    Builder* giftBuilder = new GiftBuilder();
    Director* giftDirector = new Director(giftBuilder, inv);
    
    std::cout << "Building gift bundle...\n";
    giftDirector->constructGiftBundle();
    
    DisplayBundle* gift = giftBuilder->getResult();
    if (gift != NULL) {
        std::cout << gift->toString() << "\n";
        delete gift;
    }

}

void testDecorators() {
    std::cout << "\n=== Testing Decorators ===\n";
    
    FernSupplier supplier;
    Plant* basePlant = supplier.getPlant();
    std::cout << "Base plant:\n" << basePlant->toString() << "\n";
    
    Plant* fertilizedPlant = supplier.addFertiliser(basePlant);
    std::cout << "\nFertilized plant:\n" << fertilizedPlant->toString() << "\n";
    
    Plant* protectedPlant = supplier.addFrostNet(fertilizedPlant);
    std::cout << "\nFrost protected plant:\n" << protectedPlant->toString() << "\n";
    
    delete protectedPlant; // Will cascade delete through decorators
}

int main() {
    // testInventory();
    // testTransactions();
    // testPlantLifecycle();
    testBuilderPattern();
    // testDecorators();
    
    std::cout << "\nAll tests completed.\n";
    return 0;
}