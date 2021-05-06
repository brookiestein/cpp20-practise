#include "sheep.h"

Sheep::Sheep(std::string_view name, int weight_in_pounds)
        : Animal {name, weight_in_pounds}
{}

Sheep::~Sheep() = default;

std::string
Sheep::sound() const
{
        return "Meeeeeh";
}

std::string
Sheep::who() const
{
        const int weight { getWeight() };
        return "Woolly " + getName() + " has "
                + std::to_string(weight * 0.10 + weight)
                + " pounds.";
}
