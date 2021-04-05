#include <iostream>

/* This is func()'s prototype. This makes main() to be able to use it. */
/* In other words, this makes func() to be in main()'s scope :P */
void func(void);
const double PI {3.1416}; /* Btw, I know this value is not that correct, but anyway :P */

int
main(void)
{
        int PI {3};
        std::cout << PI << std::endl; /* Accessing to the local variable. */
        /* I'm not that sure, but I think this is also called the global namespace. */
        /* I mean, using two colons without a namespace before a constant, a variable... */
        std::cout << ::PI << std::endl; /* Accessing to the global variable. */
        /* std::cout << answer << std::endl; /1* Error: answer is not at the main() scope. *1/ */
        func();
}

short answer {42};

void
func(void)
{
        std::cout << "The answer is " << answer << std::endl;
}
