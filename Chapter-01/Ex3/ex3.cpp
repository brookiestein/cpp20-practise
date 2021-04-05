/* Exercise 1-3: The following program produces several compiler errors. Find these
errors and correct them so the program can compile cleanly and run.
#import <iostream>
Int main
{
  std:cout << "Hola Mundo!" << std:endl
)
*/

/* 'I' in the 'int' keyword must go in lower case.
 * The '()', parameters zone is missing.
 * Both in the call to the 'cout' stream as the call to the 'endl' stream
 * is missing a colon symbol, i.e. ':'.
 * And by last but not least, at the end of the line, i.e. after std:endl
 * is missing a semicolon symbol, i.e. ';'. Because all statement in C++
 * finishes with a semicolon symbol.
 * As bonus, I've added the 'return' statement, but if I've learnt from this
 * chapter that, at least, in the main function it's not necessary.
 */

#include <iostream>

int
main()
{
        std::cout << "Hola Mundo!" << std::endl;
        return 0;
}
