#include <iostream>
#include <string>
#include <string_view>

int
main()
{
        std::string phrase { "Growing old is mandatory. Growing up is optional." };
        std::string_view read_only { phrase };
        /* std::string a_copy { std::string { read_only.substr(0, read_only.find('.') + 1) } }; */
        std::string a_copy { read_only.substr(0, read_only.find('.') + 1) }; /* Why does it work? */
        std::cout << a_copy << std::endl;
}
