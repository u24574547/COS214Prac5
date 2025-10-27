#include "doctest.h"
#include "../TransactionHistory.h"
#include "../Command.h"
#include "../OrderCommand.h"
#include "../RefundCommand.h"
#include "../InquiryCommand.h"
#include "../Customer.h"
#include "../Employee.h"
#include "../FernExpert.h"
#include "../Fern.h"
#include "../PlantState.h"
#include "../UnplantedState.h"

TEST_CASE("Transaction History add and remove orders") {
    TransactionHistory* history = new TransactionHistory();
    Inventory* inv = new Inventory();  

    
    PlantState* state = new UnplantedState(); 
    Plant* fern = new Fern("Ferb", 2, 0, false, 1.0, 2, state);

    inv->addPlant(fern);

    Employee* mediator = new FernExpert("Jerry", inv);

    Customer buyer("Buyer", mediator, "123");

    //create dummy commands
    Command* order = new OrderCommand(&buyer, mediator, "Moss");
    Command* anotherOrder = new OrderCommand(&buyer, mediator, "Fern");

    //add orders
    history->addOrder(order);
    // history->addOrder(anotherOrder);

    auto& items = history->getItems();
    CHECK(items.size() == 1);
    // CHECK(items[0] == order);
    // CHECK(items[1] == anotherOrder);

    //remove order
    // history->removeOrder(order);
    // CHECK(items.size() == 1);
    // CHECK(items[0] == anotherOrder);

    delete inv;
    delete state;
    delete fern;
    delete mediator;
    delete order;
    delete anotherOrder;
}