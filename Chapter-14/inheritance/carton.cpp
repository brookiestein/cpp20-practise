#include "carton.h"

Carton::Carton()
        : Box {}, m_material { "Cardboard" }
{
}

Carton::Carton(std::string_view material)
        : Box {}, m_material {material}
{
}

Carton::Carton(double side, std::string_view material)
        : Box {side}, m_material {material}
{
}

Carton::Carton(double length, double width, double height, std::string_view material)
        : Box {length, width, height}, m_material {material}
{
}

Carton::Carton(const Carton& src)
        : Box {src}, m_material {src.m_material}
{
}

std::string
Carton::getMaterial() const
{
        return m_material;
}

std::ostream&
operator<<(std::ostream& stream, const Carton& carton)
{
        /* I think that this is the polymorphism in action, but not sure :P */
        return (
                stream <<
                static_cast<Box>(carton) << ", Material = "
                << carton.getMaterial()
        );
}
