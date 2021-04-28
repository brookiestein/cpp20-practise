#include "though_pack.h"

ThoughPack::ThoughPack()
        : Box {1.0, 1.0, 1.0}
{}

ThoughPack::ThoughPack(double length, double width, double height)
        : Box {length, width, height}
{}

double
ThoughPack::volume() const
{
        return 0.85 * getLength() * getWidth() * getHeight();
}
