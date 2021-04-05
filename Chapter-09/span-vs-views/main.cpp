#include <iostream>
/* #include <vector> */
/* #include <span> */
#include <string_view>

int
main()
{
        /* This is valid because span allows me to modify the elements "it points to". */
        /* std::vector<int> numbers { 2, 4, 5, 10, 14 }; */
        /* std::span<int> sp { numbers }; */
        /* sp.front() = 5; */
        /* sp[1] *= 2; */
        /* std::cout << sp.front() << ", " << sp[1] << std::endl; */

        std::string phrase { "Don't accept the limitation of other people who claim things are 'unchangeable'. "
        "If it's written in stone, bring your hammer and chisel." };
        std::string_view view { phrase };
        /* The following is not valid because whatever operation in a string_view returns const char& */
        view[0] = 'd';
        std::cout << view << std::endl;
}
