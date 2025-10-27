#include <iostream>
#include <termios.h>
#include <unistd.h>

#include "FloweringSupplier.h"
#include "Inventory.h"

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

int main() {
    Supplier* supp = new FloweringSupplier();
    Inventory* inv = new Inventory();
    std::string menu =  "Choose an action type:\n"
    "1. Customer\n"
    "2. Plant\n"
    "3. Employee\n"
    "4. Inventory\n"
    "n to end the day\n"
    "q to quit the simulation\n"
    ;
    std::cout<<menu<<std::endl;
    char c;
    setBufferedInput(false);
    while (true) {
        c = getchar();
        if (c == '1') std::cout << "ello guvna\n";
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
