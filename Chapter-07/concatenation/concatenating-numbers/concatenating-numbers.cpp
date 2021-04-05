#include <iostream>
#include <string>

int
main(void)
{
        std::string result_string {"The result equals: "};
        result_string += std::to_string(69);
        std::cout << result_string << std::endl;
}
