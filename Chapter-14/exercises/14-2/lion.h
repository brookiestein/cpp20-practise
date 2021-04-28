#ifndef LION_H
#define LION_H

#include <string_view>

#include "animal.h"

class Lion : public Animal
{
        public:
                Lion(std::string_view name, int weight)
                        : Animal {name, weight}
                {}

                using Animal::who;

                /* Something that wasn't explained in this chapter that could
                 * work to allow the new protected version of who() is this: */
                /* void who() const { Animal::who(); } */
                /* Basically an overload of the who() member function that calls
                 * the overloaded function. A little bit barbarian, though! */
};

#endif
