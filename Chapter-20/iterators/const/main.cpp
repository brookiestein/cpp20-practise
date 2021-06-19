#include <iostream>
#include <vector>

#include "box.h"

int
main()
{
        std::vector<Box> boxes {
                {1.0, 2.0, 3.0}
        };

        auto iter { boxes.begin() };
        std::cout << *iter << "'s volume: " << iter->volume() << std::endl;

        *iter = Box { 2.0, 3.0, 4.0 };
        std::cout << *iter << "'s volume: " << iter->volume() << std::endl;

        auto const_iter { boxes.cbegin() };
        std::cout << *const_iter << "'s volume: " << const_iter->volume() << std::endl;
        /* This is not allowed. */
        /* *const_iter = Box { 7.0, 5.0, 8.0 }; */
        /* std::cout << *const_iter << "'s volume: " << const_iter->volume() << std::endl; */
}
