#include "MatureState.h"
#include "Plant.h"
#include "ReadyForSaleState.h"

void MatureState::nextState(Plant* plant) {
    //depending on conditions, transition to ReadyForSaleState
    std::cout << "Transitioning from Mature to ReadyForSale" << std::endl;
    plant->setState(new ReadyForSaleState());
}
