#include "animal.h"

Animal::Animal(std::string_view name, int weight)
        : m_name {name}, m_weight {weight}
{}

void
Animal::who() const
{
        std::cout << m_name << " has " << m_weight << " pounds." << std::endl;
}
