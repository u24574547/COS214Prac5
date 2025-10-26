#include <iostream>
#include <termios.h>
#include <unistd.h>

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
    char c;
    setBufferedInput(false);

    std::cout << "Press q to quit.\n";
    while (true) {
        c = getchar();
        if (c == 'w') std::cout << "Up\n";
        else if (c == 's') std::cout << "Down\n";
        else if (c == 'a') std::cout << "Left\n";
        else if (c == 'd') std::cout << "Right\n";
        else if (c == 'q') break;
    }

    setBufferedInput(true);
    return 0;
}
