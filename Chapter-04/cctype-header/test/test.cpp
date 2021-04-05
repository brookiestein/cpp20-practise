#include <iostream>
#include <cctype>
#include <cstring>

size_t print(std::string message, char arry[]);

int
main(void)
{
        std::string input {};

        std::cout << "Enter a phrase: ";
        std::cin >> input;

        size_t size {input.size()};
        char uppers[size];
        char lowers[size];

        for (size_t i = 0, j = 0, k = 0; i < size; i++) {
                if (std::isupper(input[i])) {
                        uppers[j++] = input[i];
                } else if (std::islower(input[i])) {
                        lowers[k++] = input[i];
                }
        }

        print("The following characters are uppers:", uppers);
        print("The following characters are lowers:", lowers);
}

size_t
print(std::string message, char arr[])
{
        std::cout << message << std::endl;
        size_t size {std::strlen(arr)};
        size_t i {}; /* The returned value. */

        for (i = 0; i < size; i++) {
                if (i < size - 1) {
                        std::cout << arr[i] << ", ";
                } else {
                        std::cout << arr[i] << std::endl;
                }
        }

        return i;
}
