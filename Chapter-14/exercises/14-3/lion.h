#ifndef LION_H
#define LION_H

#include <string_view>
#include <iostream>

#include "animal.h"

class Lion : public Animal
{
        public:
                Lion(std::string_view name, int weight)
                        : Animal {name, weight}
                {}

                void who() const
                {
                        std::cout << "Lion Class:" << std::endl;
                        Animal::who();
                }
};

#endif
