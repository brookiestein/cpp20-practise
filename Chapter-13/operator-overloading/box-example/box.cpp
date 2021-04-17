/* Making the operator<() operator inside the class
 * allows it to have the this pointer and thus, it
 * can access the members of the class, and also
 * only needs a argument to work.
 * Making the operator<() operator outside the class
 * makes the operator to receive two arguments to work
 * and won't have the this operator. Neither can access
 * the members of the class, unless you define it as a
 * friend of the class.
 */

#include "box.h"

Box::Box() = default;
Box::Box(double length, double width, double height)
        : m_length {length}, m_width {width}, m_height {height}
{
}

double
Box::getLength() const { return m_length; }

double
Box::getWidth() const { return m_width; }

double
Box::getHeight() const { return m_height; }

double
Box::getVolume() const
{
        return m_length * m_width * m_height;
}

/* Member of the class version: */
bool
Box::operator < (const Box& box) const
{
        return getVolume() < box.getVolume();
}

bool
Box::operator < (double value) const
{
        return getVolume() < value;
}

/* Outside the class version: */
bool
operator < (double value, const Box& box)
{
        return value < box.getVolume();
}
