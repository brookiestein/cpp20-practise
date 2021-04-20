#include "integer.h"

Integer::Integer(int value)
        : m_value {value}
{}

int
Integer::getValue() const
{
        return m_value;
}

void
Integer::setValue(int value)
{
        m_value = value;
}

Integer
Integer::operator+(const Integer& another)
{
        return getValue() + another.getValue();
}

Integer
Integer::operator-(const Integer& another)
{
        return getValue() - another.getValue();
}

Integer
Integer::operator*(const Integer& another)
{
        return getValue() * another.getValue();
}

Integer
Integer::operator/(const Integer& another)
{
        return getValue() / another.getValue();
}

std::ostream&
operator<<(std::ostream& stream, const Integer& obj)
{
        /* Parenthesis are unnecessary, but makes code clearer. */
        return ( stream << obj.getValue() );
}
