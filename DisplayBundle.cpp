#include "DisplayBundle.h"
//manditory change for commit
void DisplayBundle::add(Bundle* b) {
    components.push_back(b);
}

std::string DisplayBundle::toString() const {
    std::stringstream ss;
    ss<< "Display Bundle contains:" << std::endl;
    // std::cout<<"SIZE: "<<components.size()<<std::endl;
    for (size_t i = 0; i < components.size(); i++){
        // std::cout<<"HERE"<<std::endl;
        ss<<components[i]->toString();
    }
    return ss.str();
}

DisplayBundle::~DisplayBundle() {
    for (size_t i = 0; i < components.size(); ++i)
        delete components[i];
}
