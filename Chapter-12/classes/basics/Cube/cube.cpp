#include "cube.h"

/* Using member initializer list */
Cube::Cube(double side) : m_side {side}
{
}

double Cube::getVolume() { return (m_side * m_side * m_side); }

/* This method receives an instance of the same class.
 * Notice that even though cube has the getVolume() method
 * it is not the same than the object's which is calling this method.
 * For example, suppose you have:
 * Cube cube1;
 * Cube cube2;
 * And you call:
 * cube1.hasLargerVolumeThan(cube2)
 * cube 1's getVolume() method is not the same than cube 2's! */
bool Cube::hasLargerVolumeThan(Cube cube)
{
        return getVolume() > cube.getVolume();
}
