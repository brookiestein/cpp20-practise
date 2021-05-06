#include "animal.h"

Animal::Animal(std::string_view name, int weight_in_pounds)
        : m_name {name}, m_weight {weight_in_pounds}
{}

Animal::~Animal() = default;

std::string
Animal::who() const
{
        return m_name + " has " + std::to_string(m_weight) + " pounds.";
}

std::string
Animal::getName() const
{
        return m_name;
}

int
Animal::getWeight() const
{
        return m_weight;
}
