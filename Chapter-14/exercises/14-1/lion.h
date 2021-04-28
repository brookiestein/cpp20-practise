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
};

#endif
