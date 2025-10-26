#include "DisplayBundle.h"
#include <iostream>
//manditory change for commit
void DisplayBundle::add(Bundle* b) {
    components.push_back(b);
}

void DisplayBundle::display() const {
    std::cout << "Display Bundle contains:" << std::endl;
    for (size_t i = 0; i < components.size(); ++i)
        components[i]->display();
}

DisplayBundle::~DisplayBundle() {
    for (size_t i = 0; i < components.size(); ++i)
        delete components[i];
}
