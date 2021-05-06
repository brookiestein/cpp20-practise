#ifndef SHEEP_H
#define SHEEP_H

#include <string>
#include <string_view>

#include "animal.h"

class Sheep : public Animal
{
        public:
                Sheep(std::string_view name, double weight_in_pounds);
                ~Sheep(); /* Notice that the destructor will be virtual because of Animal's inheritance. */
                std::string sound() const override;
                std::string getName() const override;
                double getWeight() const override;
                double shear();
};

#endif
