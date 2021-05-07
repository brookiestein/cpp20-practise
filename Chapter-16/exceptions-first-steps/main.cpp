/* Throwing and catching exceptions of type size_t and [const] char* */

#include <iostream>

int
main()
{
        for (size_t i {}; i < 5; ++i) {
                try {
                        if (i < 2)
                                throw i;

                        std::cout << "i not thrown - value is " << i << '\n';

                        if (i > 3)
                                throw "Here is another!";

                        std::cout << "End of the try block." << std::endl;
                } catch (size_t i) {
                        std::cout << "i caught - value is " << i << std::endl;
                } catch (const char* message) {
                        std::cout << "Message caught - value is \""
                                << message << '"' << std::endl;
                }

                std::cout << "End of the try block (After the catch blocks)." << std::endl;
        }
}
