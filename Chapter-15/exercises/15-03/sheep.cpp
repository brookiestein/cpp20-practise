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
Sheep::getName() const
{
        return "Woolly " + Animal::getName();
}

int
Sheep::getWeight() const
{
        return Animal::getWeight() - (Animal::getWeight() * 0.10);
}
