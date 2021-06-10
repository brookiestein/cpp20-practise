#include <iostream>

void print(const char* message);

int
main()
{
        auto* func { &print };
        func("Hello world!");
}

void
print(const char* message)
{
        std::cout << message << std::endl;
}
