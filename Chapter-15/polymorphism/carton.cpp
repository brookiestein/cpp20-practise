#include "carton.h"

Carton::Carton()
        : Box {1.0, 1.0, 1.0}, m_material {"Cardboard"}
{}

Carton::Carton(double l, double w, double h, std::string_view material)
        : Box {l, w, h}, m_material {material}
{}

double
Carton::volume(int i) const
{
        std::cout << "(Carton argument = " << i << ") " << std::endl;
        double volume { (getLength() - 0.5) * (getWidth() - 0.5) * (getHeight() - 0.5) };
        return std::max(volume, 0.0);
}

std::string
Carton::getMaterial() const
{
        return m_material;
}
