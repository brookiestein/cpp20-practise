/* It's recommendable to reset a freed pointer assigning it nullptr.
 * But is it a bad practise not to reset a pointer and instead assigning
 * another address in it?
 */

#include <iostream>

int
main(void)
{
        unsigned int *age = {new unsigned int {19}};
        std::cout << "I'm " << *age << " years old." << std::endl;
        delete age;

        age = new unsigned int {20};
        std::cout << "In my next birthday I'll turn to " << *age << '.' << std::endl;
        delete age;
        age = nullptr;
}
