#include "can.h"

Can::Can(double diameter, double height)
        : m_diameter {diameter}, m_height {height}
{
        std::cout << "Can(double, double) called." << std::endl;
}

Can::~Can()
{
        std::cout << "Can's destructor called." << std::endl;
}

double
Can::volume() const
{
        return M_PI * std::pow(m_diameter, 2.0) * m_height / 4;
}
