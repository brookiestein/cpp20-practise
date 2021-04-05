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
}
