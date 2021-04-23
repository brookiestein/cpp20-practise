/* Exercise 13-3. Take another look at your solution of Exercise 13-2. If it’s anything */
/* like our model solution, it contains two binary arithmetic operators: one to add two */
/* Box es and one overloaded operator to multiply Box es by numbers. Remember that */
/* we said that one thing always leads to another in the world of operator overloading? */
/* While subtracting Box es does not work well, surely if you have operators to multiply */
/* with an integer, you’d also want operators to divide by one? Furthermore, each binary */
/* arithmetic operator op () creates the expectation of a corresponding compound */
/* assignment operator op =() . Make sure to implement all requested operators using the */
/* canonical patterns! */

#include <iostream>

#include "box.h"

int
main()
{
        Box box0 {2.5, 3.2, 7.4};
        Box box1 {3.0, 2.0, 1.0};
        Box addedBox {box0 + box1};
        Box postmultipliedBox {box0 * 5.0};
        Box premultipliedBox {2.0 * box1};
        Box dividedBox {box0 / 2.0};

        std::cout << "Box 0: (" << box0 << ')' << std::endl;
        std::cout << "Box 1: (" << box1 << ')' << std::endl;
        std::cout << "Adding Box 0 and Box 1: (" << addedBox << ')' << std::endl;
        std::cout << "Post multiplying Box 0 and 2.0: (" << postmultipliedBox << ')' << std::endl;
        std::cout << "Pre multiplying Box 0 and 2.0: (" << premultipliedBox << ')' << std::endl;
        std::cout << "Dividing Box 0 / 2.0: (" << dividedBox << ')' << std::endl;

        std::cout << std::endl;

        box0 += box1; /* Expects (3.0 3.2 8.4) */
        std::cout << "Box 0 after being added with Box 1: (" << box0 << ')' << std::endl;
        box0 *= 2.0; /* Expects (6.0 6.4 16.8) */
        std::cout << "Box 0 after being multiplied with 2.0: (" << box0 << ')' << std::endl;
        box0 /= 2.0; /* The same than += statement */
        std::cout << "Box 0 after being divided with 2.0: (" << box0 << ')' << std::endl;
}
