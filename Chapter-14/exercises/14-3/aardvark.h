#ifndef AARDVARK_H
#define AARDVARK_H

#include <string_view>
#include <iostream>

#include "animal.h"

class Aardvark : public Animal
{
        public:
                Aardvark(std::string_view name, int weight)
                        : Animal {name, weight}
                {}

                void who() const
                {
                        std::cout << "Aardvark Class:" << std::endl;
                        Animal::who();
                }
};

#endif
