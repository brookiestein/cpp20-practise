#include <iostream>
#include <string>

int
main(void)
{
        std::string name0 {"Brayan Perez"};
        std::string name1 {"Brayan"};

        if (name0.compare(0, name1.length(), name1) == 0) {
                std::cout << "They're equal from 0 until " << name1.length() << std::endl;
                std::cout << name0.substr(0, name1.length()) << '$' << std::endl;
        }
}
