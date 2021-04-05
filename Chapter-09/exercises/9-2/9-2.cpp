/* Exercise 9-2. Adjust Ex8_11 to use std::string_view and std::span<>. */
#include <iostream>
#include <vector>
#include <span>

void show_data(std::span<const int> data,
                std::string_view title = "Data Values",
                size_t perline = 5);

int
main()
{
        std::vector<int> numbers  { 14, 70, 55, 256, 512, 2048 };
        std::vector<int> numbers2 { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        /* In this case I had to hardcode the second parameter,
         * because, even though I'm ok with it, I can't leave it
         * blank and just pass the function the third parameter. */
        show_data(numbers, "Data Values", 3);
        show_data(numbers2, "Numbers");
}

void
show_data(std::span<const int> data, std::string_view title, size_t perline)
{
        std::cout << title << std::endl;
        size_t count {};
        for (auto value : data) {
                std::cout << value << ' ';
                if (++count % perline == 0)
                        std::cout << std::endl;
        }
        std::cout << std::endl;
}
