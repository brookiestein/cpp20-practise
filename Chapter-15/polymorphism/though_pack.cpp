#include "though_pack.h"

ThoughPack::ThoughPack()
        : Box {1.0, 1.0, 1.0}
{}

ThoughPack::ThoughPack(double length, double width, double height)
        : Box {length, width, height}
{}

ThoughPack::ThoughPack(const Box& box)
        : Box {box}
{}

ThoughPack::~ThoughPack()
{
        std::cout << "ThoughPack destructor called." << std::endl;
}

double
ThoughPack::volume() const
{
        return 0.85 * getLength() * getWidth() * getHeight();
}
