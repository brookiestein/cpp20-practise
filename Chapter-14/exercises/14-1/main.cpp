/* Exercise 14-1. Define a base class called Animal that contains two private member variables: */
/* a string to store the m_name of the animal (e.g., “Fido” or “Yogi”) and an integer member called */
/* m_weight that will contain the weight of the animal in pounds. Also include a public member */
/* function, who() , that outputs a message giving the name and weight of the Animal object. */
/* Derive two classes named Lion and Aardvark , with Animal as a public base class. Write a */
/* main() function to create Lion and Aardvark objects (“Leo” at 400 pounds and “Algernon” at */
/* 50 pounds, say) and demonstrate that the who() member is inherited in both derived classes */
/* by calling it for the derived class objects. */

#include <iostream>

#include "lion.h"
#include "aardvark.h"

int
main()
{
        Lion lion { "Leo", 400 };
        Aardvark advk { "Algernon", 50 };

        lion.who();
        advk.who();
}
