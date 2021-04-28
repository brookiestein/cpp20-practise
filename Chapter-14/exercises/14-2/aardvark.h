#ifndef AARDVARK_H
#define AARDVARK_H

#include <string_view>

#include "animal.h"

class Aardvark : public Animal
{
        public:
                Aardvark(std::string_view name, int weight)
                        : Animal {name, weight}
                {}

                using Animal::who;
};

#endif
