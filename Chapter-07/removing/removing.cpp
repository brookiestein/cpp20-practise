#include <iostream>
#include <string>

int
main(void)
{
        std::string nick {"Lord Brookie"};

        /* "Simulating" the work done by std::erase() */
        for (size_t i {}; i < nick.length(); ++i) {
                if (nick[i] == 'o')
                        nick.erase(i, 1);
        }

        std::cout << nick << std::endl;
}
