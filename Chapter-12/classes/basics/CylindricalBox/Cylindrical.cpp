#include "Cylindrical.h"

Cylindrical::Cylindrical(double radius, double height, std::string_view material)
        : m_radius {radius}, m_height {height}, m_material {material}
{}

double
Cylindrical::getVolume() const
{
        return m_radius * m_radius * m_height * PI;
}
