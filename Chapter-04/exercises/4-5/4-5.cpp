/*
 * Add some code to the end of the main() function of Ex4_07.cpp to print an
 * additional message. If you have exactly one mouse, output a message of the form “It is a
 * brown/white mouse.” Otherwise, if you have multiple mice, compose a grammatically correct
 * message of the form “Of these mice, N is a/are brown mouse/mice.” If you have no mice, no
 * new message needs to be printed. Use an appropriate mixture of conditional operators and
 * if / else statements.
 */

#include <iostream>

int
main(void)
{
        int mice {};
        int brown {};
        int white {};

        std::cout << "How many brown mice do you have? ";
        std::cin >> brown;
        std::cout << "How many white mice do you have? ";
        std::cin >> white;

        mice = brown + white;

        std::cout << "You have " << mice << (mice == 1 ? " mouse" : " mice") << std::endl;

        if (!mice) {
                return 0;
        } else if (mice == 1) {
                std::cout << "It is a white mouse." << std::endl;
                return 0;
        }

        std::cout << "Of these mice, "
                << static_cast<int>((mice * 0.50))
                << (static_cast<int>(mice * 0.50) > 1 ? " are white mice" : " is a white mouse")
                << " and the others are brown."
                << std::endl;
}
