/* This program tests whether a function can be called even though it hadn't been defined, only with its prototype. */
/* Ok. It couldn't xD. */
#include <iostream>

int life_s_answer();

int
main()
{
        std::cout << "The life's answer is " << life_s_answer() << std::endl;
}

int
life_s_answer()
{
        return 42;
}
