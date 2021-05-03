#include "carton.h"

Carton::Carton()
        : Box {1.0, 1.0, 1.0}, m_material {"Cardboard"}
{
        std::cout << "Carton() called." << std::endl;
}

Carton::Carton(double l, double w, double h, std::string_view material)
        : Box {l, w, h}, m_material {material}
{
        std::cout << "Carton(double, double, double, string_view) called." << std::endl;
}

Carton::Carton(const Box& box, std::string_view material)
        : Box {box}, m_material {material}
{
        std::cout << "Carton(Box&, string_view) called." << std::endl;
}

Carton::~Carton()
{
        std::cout << "Carton destructor called." << std::endl;
}

double
Carton::volume() const
{
        double volume { (getLength() - 0.5) * (getWidth() - 0.5) * (getHeight() - 0.5) };
        return std::max(volume, 0.0);
}

std::string
Carton::getMaterial() const
{
        return m_material;
}
