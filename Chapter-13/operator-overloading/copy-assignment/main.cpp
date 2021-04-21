#include <iostream>

#include "message.h"

int
main()
{
        Message message {"Hello world!"};
        Message hello {message};
        Message bye;
        std::string bye_str {"Bye world!"};
        bye = bye_str;

        std::cout << hello << std::endl;
        std::cout << bye << std::endl;
}
