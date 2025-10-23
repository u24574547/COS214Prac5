#include "ReadyForSaleState.h"
#include "Plant.h"
#include "DormantState.h"
#include "SoldState.h"

void ReadyForSaleState::nextState(Plant* plant) {
    if (plant->isSold()) {
        std::cout << "Plant sold! Transitioning to Sold" << std::endl;
        plant->setState(new SoldState());
    }
}
