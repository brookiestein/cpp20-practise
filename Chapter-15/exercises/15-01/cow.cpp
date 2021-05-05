#include "cow.h"

Cow::Cow(std::string_view name, int weight_in_pounds)
        : Animal {name, weight_in_pounds}
{}

Cow::~Cow() = default;

std::string
Cow::sound() const
{
        return "Muuuuuuuh";
}
