#include <iostream>
#include <string>

int
main(void)
{
        std::string word {"Word"};
        std::cout << word.find_last_not_of("AaEeIiOoUu") << std::endl;
}
