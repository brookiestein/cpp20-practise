#include "dog.h"

Dog::Dog(std::string_view name, double weight_in_pounds)
        : Animal {name, weight_in_pounds}
{}

Dog::~Dog() = default;

std::string
Dog::sound() const
{
        return "Woooof";
}
