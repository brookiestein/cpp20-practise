/* This is a version of the exercise done in chapter 5, exactly Ex5_09
 * but using strings and vector instead. */

#include <iostream>
#include <string>
#include <vector>

int
main(void)
{
        std::vector<std::string> names;

        for (;;) {
                std::string input {};
                std::cout << "Enter a name, leave it blank to end: ";
                std::getline(std::cin, input);
                if (input.empty()) break;
                names.push_back(input);
        }

        bool sorted {};
        do {
                sorted = true;
                for (size_t i {1}; i < names.size(); ++i) {
                        if (names[i - 1] > names[i]) {
                                names[i].swap(names[i - 1]);
                                sorted = false;
                        }
                }
        } while (!sorted);

        size_t max_length {};
        for (const auto& name : names) {
                if (max_length < name.length()) {
                        max_length = name.length();
                }
        }

        const size_t field_width {max_length + 2};
        size_t count {};

        std::cout << "\nThe names you've entered in ascending order are:" << std::endl;
        for (const auto& name : names) {
                std::cout << name;
                for (size_t i {}; i < field_width; ++i) std::cout << ' ';
                if (!(++count % 5)) std::cout << std::endl;
        }
        std::cout << std::endl;
}
