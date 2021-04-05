/* Passing arguments to main when program starts. */

#include <iostream>

int
main(int argc, char *argv[])
{
        std::cout << "You've entered the following "
                << argc << " arguments:\n";
        for (size_t i {}; i < argc; ++i)
                std::cout << argv[i] << ' ';
        std::cout << std::endl;
}
