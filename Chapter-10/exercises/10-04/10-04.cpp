/* Exercise 10-4. Write your own version of the std::size() family of functions called my_size() */
/* that work not only for fixed-size arrays but also for std::vector<> and std::array<> objects. */
/* You are not allowed to use the sizeof() operator. */

#include <iostream>
#include <vector>
#include <array>

template <typename T> size_t my_size(const T& container);

int
main()
{
        int ints[] {1, 2, 3, 4, 5};
        std::vector<double> doubles {1.15, 2.16, 3.14, 66.6, 700.432, 1000.001};
        std::array<unsigned, 3> unsigneds {3, 7, 50};

        size_t ints_size { my_size(ints) };
        size_t doubles_size { my_size(doubles) };
        size_t unsigneds_size { my_size(unsigneds) };

        std::cout << "ints' size: " << ints_size << std::endl;
        std::cout << "doubles' size: " << doubles_size << std::endl;
        std::cout << "unsigneds' size: " << unsigneds_size << std::endl;
}

template <typename T> size_t
my_size(const T& container)
{
        size_t size {};
        for (const auto& value : container)
                ++size;
        return size;
}
