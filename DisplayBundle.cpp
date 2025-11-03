#include "DisplayBundle.h"
//manditory change for commit
DisplayBundle::DisplayBundle() : Bundle() {}
void DisplayBundle::add(Bundle* b) {
    components.push_back(b);
}

std::string DisplayBundle::toString() const {
    std::stringstream ss;
    ss<< "Display Bundle contains: "<<components.size()<<" plants" << std::endl;
    // std::cout<<"SIZE: "<<components.size()<<std::endl;
    for (size_t i = 0; i < components.size(); i++){
        // std::cout<<"HERE"<<std::endl;
        ss<<components[i]->toString();
        ss<<"\n";
    }
    return ss.str();
}

double DisplayBundle::getPrice() {
    double total = 0.0;
    for (size_t i = 0; i < components.size(); ++i)
        total += components[i]->getPrice();
    return total;
}

DisplayBundle::~DisplayBundle() {
    for (size_t i = 0; i < components.size(); ++i)
        delete components[i];
}
