#include <iostream>
#include <string>

void show_data(const int data[], size_t count = 1,
                const std::string& title = "Data Values",
                size_t per_line = 5);

int
main(void)
{
        int data[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int num {-99};
        show_data(&num);
        show_data(data, std::size(data), "Showing data's items");
        int values[] {1, 2, 3};
        show_data(values, std::size(values));
}

void
show_data(const int data[], size_t count,
        const std::string& title, size_t perline)
{
        std::cout << title << std::endl;
        for (size_t i {}; i < count; ++i) {
                std::cout << data[i] << ' ';
                if ((i + 1) % perline == 0) std::cout << std::endl;
        }
        std::cout << std::endl;
}
