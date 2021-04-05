#include <iostream>
#include <string>

int
main(void)
{
        std::string first; /* User's first name. */
        std::string second; /* User's second name. */

        std::cout << "Enter your first name: ";
        std::cin >> first;
        std::cout << "Enter your second name: ";
        std::cin >> second;

        std::string sentence {"Your name is "};
        /* sentence += first + " " + second + "."; */
        sentence.append(first).append(" ").append(second).append(".");
        std::cout << sentence << " and it has " << sentence.length()
                << " characters." << std::endl;
}
