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

void testInventory() {
    Inventory* inv = new Inventory(); 

    PlantState* state = new UnplantedState(); 
    Plant* fern = new Fern("Ferb", 2, 0, false, 1.0, 2, state);
    Plant* moss = new Moss("Boss", 2, 0, false, 1.0, 2, state);
    Plant* flowrering = new Flowering("Bowring", 2, 0, false, 1.0, 2, state);
    
    std::cout << "==============ADDING PLANTS TO INVENTORY=================\n";
    inv->addPlant(fern);
    inv->addPlant(moss);
    inv->addPlant(flowrering);

    std::cout << std::endl;
    std::cout << "==============ITERATING THROUGH INVENTORY=================\n";  

    Iterator<Plant*>* it = inv->createIterator();
    for (it->first(); !it->isDone(); it->next()) {
        std::cout << "Plant species: " <<
        it->current()->getSpecies() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "==============REMOVING PLANT(S)=================\n"; 
    
    std::cout << "Removed " << inv->getPlant("Boss")->getSpecies() << "\n";
    
    std::cout << std::endl;
    std::cout << "==============ITERATING THROUGH INVENTORY=================\n"; 
    for (it->first(); !it->isDone(); it->next()) {
        std::cout << "Plant species: " <<
        it->current()->getSpecies() << std::endl;
    }

}

void testTransasctions() {
    TransactionHistory* history = new TransactionHistory();
    Inventory* inv = new Inventory();  

    
    PlantState* state = new UnplantedState(); 
    Plant* fern = new Fern("Ferb", 2, 0, false, 1.0, 2, state);
    Plant* moss = new Moss("Boss", 2, 0, false, 1.0, 2, state);
    inv->addPlant(fern);
    inv->addPlant(moss);

    Employee* mediator = new FernExpert("Jerry", inv);

    Customer* frank = new Customer("Frank", mediator, "123");
    Customer* manny = new Customer("Manny", mediator, "456");

    //create dummy commands
    Command* order = new OrderCommand(frank, mediator, "Moss");
    Command* anotherOrder = new OrderCommand(manny, mediator, "Fern");

    //add orders
    std::cout << "==============ADDING ORDERS=================\n"; 
    history->addOrder(order);
    history->addOrder(anotherOrder);
    std::cout << std::endl;

    std::cout << "==============TRAVERSING THROUGH ORDERS=================\n"; 
    Iterator<Command*>* iterator = history->createIterator();
    for (iterator->first(); !iterator->isDone(); iterator->next()) {
        std::cout << "Transaction from: " << iterator->current()->getCustomer()->getName() << "\n";
    }
    std::cout << "==============CAPTURING ORDER STATE=================\n"; 
    TransactionMemento* mem = history->captureState();
    std::vector<Command*> transactions = mem->getTransactions();

    for (auto it = transactions.begin(); it!= transactions.end(); it++) {
        std::cout << "Transaction from:" << (*it)->getCustomer()->getName() << '\n';
    }
    std::cout << std::endl;

    std::cout << "==============REMOVING ORDERS=================\n"; 
    history->removeOrder(order);

    std::cout << std::endl;
    std::cout << "==============TRAVERSING THROUGH ORDERS=================\n"; 

    for (iterator->first(); !iterator->isDone(); iterator->next()) {
        std::cout << "Transaction from: " << iterator->current()->getCustomer()->getName() << "\n";
    }

    std::cout << std::endl;

    delete order;
    delete anotherOrder;
    delete frank;
    delete manny;
    delete state;
    delete inv;
    delete mediator;
    delete history;

}

int main () {
    // testInventory();
    testTransasctions();
    return 0;
}