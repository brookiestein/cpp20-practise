/* Exercise 16-5. Create a function called readEvenNumber() intended to read an even integer */
/* from the std::cin input stream. About 25% of the time something really odd happens inside */
/* readEvenNumber() , resulting in a CurveBall exception. You can simply reuse code from */
/* Exercise 16-1 for this. Normally, however, the function verifies the user input and returns an */
/* even number if the user enters one correctly. If the input is not valid, however, the function */
/* throws one of the following exceptions: */
/* • If any value is entered that is not a number, it throws a NotANumber exception. */
/* • If the user enters a negative number, a NegativeNumber exception is thrown. */
/* • If the user enters an odd number, the function throws an OddNumber exception. */
/* You should derive these new exception types from std::domain_error , one of the standard */
/* exception types defined in the <stdexcept> module. Their constructors should compose a */
/* string containing at least the incorrectly entered value and then forward that string to the */
/* constructor of std::domain_error . */
/* Hint: After attempting to read an integer number from std::cin , you can check whether */
/* parsing that integer succeeded by using std::cin.fail() . If that member function returns */
/* true , the user entered a string that is not a number. Note that once the stream is in such */
/* a failure state, you cannot use the stream anymore until you call std::cin.clear() . Also, */
/* the nonnumeric value the user had entered will still be inside the stream—it is not removed */
/* when failing to extract an integer. You could, for instance, extract it using the std::getline() */
/* function defined in <string> . Putting this all together, your code might contain something like */
/* this: */
/* if (std::cin.fail()) */
/* { */
/*   std::cin.clear();  // Reset the failure state */
/*   std::string line;  // Read the erroneous input and discard it */
/*   std::getline(std::cin, line); */
/*   ... */
/* Once the readEvenNumber() helper is ready, use it to implement askEvenNumber() . This */
/* function prints user instructions to std::cout and then calls readEvenNumber() to handle the */
/* actual input and input verification. Once a number is read correctly, askEvenNumber() politely */
/* thanks the user for entering the number (the message should contain the number itself). For */
/* any std::exception that readEvenNumber() throws, askEvenNumber() should at least */
/* output e.what() to std::cerr . Any exception that is not a domain_error is to be rethrown, */
/* and askEvenNumber() has no idea how to handle these. If the exception is a domain_error , */
/* however, you should retry asking for an even number, unless the exception is a NotANumber . If */
/* a NotANumber occurs, askEvenNumber() stops asking for numbers and simply returns. */
/* Finally, write a main() function that executes askEvenNumber() and catches any CurveBall s */
/* that may come out. If it catches one, it should output “…hit it out of the park!” because that’s */
/* what you do when life throws you a curveball! */

/* Notice that I didn't implement the solution to clear the std::cin stream because since
 * when a NotANumber exception is thrown the function just returns it becomes unnecessary
 * to do that because the program ends, at least in the way I've implemented it. */

#include <iostream>
#include <stdexcept>

#include "exceptions.h"

static int readEvenNumber();
static void askEvenNumber();

int
main()
{
        /* Calling this function like this causes the program to finish
         * if an exception that's not a domain_error exception is thrown. */
        askEvenNumber();
}

static int
readEvenNumber()
{
        int even {};
        std::cin >> even;

        if (std::cin.fail()) {
                throw NotANumber {"You've not entered a valid number."};
        }

        if (even < 0)
                throw NegativeNumber {"Negative numbers are not allowed.", even};
                /* If this is not true... */
        if (even % 2)
                throw OddNumber {"You've not entered a valid even number.", even};

        return even;
}

static void
askEvenNumber()
{
        while (true) {
                int evenNumber {};
                std::cout << "Enter an even number: ";
                try {
                        evenNumber = readEvenNumber();
                        std::cout << "Thank you for entering " << evenNumber << "!\n";
                        break;
                } catch (const NotANumber& ex) {
                        std::cout << ex.what() << std::endl;
                        break;
                } catch (const std::domain_error& ex) {
                        std::cout << ex.what() << std::endl;
                } catch (...) {
                        throw;
                }
        }
}
