#include "carton.h"

Carton::Carton()
        : m_material { "Cardboard" }
{
        std::cout << "Carton() called." << std::endl;
}

Carton::Carton(std::string_view material)
        : m_material {material}
{
        std::cout << "Carton(std::string_view) called." << std::endl;
}

Carton::Carton(double side, std::string_view material)
        : Box {side}, m_material {material}
{
        std::cout << "Carton(double, std::string_view) called." << std::endl;
}

Carton::Carton(double length, double width, double height, std::string_view material)
        : Box {length, width, height}, m_material {material}
{
        std::cout << "Carton(double, double, double, std::string_view) called." << std::endl;
}

std::string
Carton::getMaterial() const
{
        return m_material;
}
