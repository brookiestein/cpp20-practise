#ifndef SHEEP_H
#define SHEEP_H

#include <string>
#include <string_view>

#include "animal.h"

class Sheep : public Animal
{
        public:
                Sheep(std::string_view name, int weight_in_pounds);
                ~Sheep(); /* Notice that the destructor will be virtual because of Animal's inheritance. */
                std::string sound() const override;
};

#endif
