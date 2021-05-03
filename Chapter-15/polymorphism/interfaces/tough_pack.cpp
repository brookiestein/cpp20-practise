#include "tough_pack.h"

ToughPack::ToughPack()
        : Box {1.0, 1.0, 1.0}
{
        std::cout << "ToughPack() called." << std::endl;
}

ToughPack::ToughPack(double length, double width, double height)
        : Box {length, width, height}
{
        std::cout << "ToughPack(double, double, double) called." << std::endl;
}

ToughPack::ToughPack(const Box& box)
        : Box {box}
{
        std::cout << "ToughPack(Box&) called." << std::endl;
}

ToughPack::~ToughPack()
{
        std::cout << "ToughPack destructor called." << std::endl;
}

double
ToughPack::volume() const
{
        return 0.85 * getLength() * getWidth() * getHeight();
}
