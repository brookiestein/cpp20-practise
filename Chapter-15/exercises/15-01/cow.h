#ifndef COW_H
#define COW_H

#include <string>
#include <string_view>

#include "animal.h"

class Cow : public Animal
{
        public:
                Cow(std::string_view name, int weight_in_pounds);
                ~Cow();
                std::string sound() const override;
};

#endif
