#ifndef COW_H
#define COW_H

#include <string>
#include <string_view>

#include "animal.h"

class Cow : public Animal
{
        public:
                Cow(std::string_view name, double weight_in_pounds);
                ~Cow();
                std::string sound() const override;
                std::string who() const override;
};

#endif
