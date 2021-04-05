/* Exercise 8-3. Write a program that accepts from two to four command-line arguments. If it is
 * called with less than two or more than four arguments, output a message telling the user what
 * they should do and then exit. If the number of arguments is correct, output them, each on a
 * separate line. */

#include <iostream>

int
main(int argc, char *argv[])
{
        if (argc < 3 || argc > 5) {
                std::cout << "Usage: ./program [<arg1> <arg2> <arg3> <arg4>]" << std::endl;
                std::cout << "You could pass this program from two to four arguments." << std::endl;
                return 0;
        }

        for (size_t i {}; i < argc; ++i)
                std::cout << argv[i] << std::endl;
}
