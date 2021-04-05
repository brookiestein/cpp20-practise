#include <iostream>
#include <string>

int
main(void)
{
        std::string name { "Brayan" };
        std::cout << "My name is " << name
                << " and my name has a length of " << name.length()
                << " characters." << std::endl;
}
