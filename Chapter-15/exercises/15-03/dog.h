#ifndef DOG_H
#define DOG_H

#include <string>
#include <string_view>

#include "animal.h"

class Dog : public Animal
{
        public:
                Dog(std::string_view name, int weight_in_pounds);
                ~Dog();
                std::string sound() const override;
};

#endif
