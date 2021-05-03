#include "though_pack.h"

ThoughPack::ThoughPack()
        : Box {1.0, 1.0, 1.0}
{
        std::cout << "ThoughPack() called." << std::endl;
}

ThoughPack::ThoughPack(double length, double width, double height)
        : Box {length, width, height}
{
        std::cout << "ThoughPack(double, double, double) called." << std::endl;
}

ThoughPack::ThoughPack(const Box& box)
        : Box {box}
{
        std::cout << "ThoughPack(Box&) called." << std::endl;
}

ThoughPack::~ThoughPack()
{
        std::cout << "ThoughPack destructor called." << std::endl;
}

double
ThoughPack::volume() const
{
        return 0.85 * getLength() * getWidth() * getHeight();
}
