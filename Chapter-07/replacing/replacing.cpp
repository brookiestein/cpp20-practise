#include <iostream>
#include <string>

int
main(void)
{
        std::string nick {"Lord Brookie"};
        std::string nick2 {"Orochimaru"};

        nick.replace(5, nick.substr(5).length(), nick2.substr(0, 6));

        std::cout << nick << std::endl;
}
