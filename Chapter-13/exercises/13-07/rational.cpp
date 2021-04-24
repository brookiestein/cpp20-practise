#include "rational.h"

Rational::Rational(int numerator, int denominator)
        : m_numerator {numerator}, m_denominator {denominator}
{}

int
Rational::getNumerator() const
{
        return m_numerator;
}

int
Rational::getDenominator() const
{
        return m_denominator;
}

void
Rational::setNumerator(int numerator)
{
        m_numerator = numerator;
}

void
Rational::setDenominator(int denominator)
{
        m_denominator = denominator;
}

Rational::operator double() const
{
        return static_cast<double>(m_numerator) / m_denominator;
}

Rational::operator float() const
{
        return static_cast<float>(m_numerator) / m_denominator;
}

auto
Rational::operator<=>(const Rational& r) const
{
        return m_numerator * r.m_denominator <=> r.m_numerator * m_denominator;
}

auto
Rational::operator<=>(double number) const
{
        return static_cast<double>(*this) <=> number;
}

auto
Rational::operator==(const Rational& r) const
{
        return m_numerator * r.m_denominator == r.m_numerator * m_denominator;
}

auto
Rational::operator==(double number) const
{
        return static_cast<double>(*this) == number;
}

Rational
Rational::operator-() const
{
        return Rational {-m_numerator, m_denominator};
}

Rational::operator bool() const
{
        return m_numerator != 0;
}

Rational&
Rational::operator+=(const Rational& r)
{
        m_numerator   = m_numerator * r.m_denominator + r.m_numerator * m_denominator;
        m_denominator = m_denominator * r.m_denominator;
        return *this;
}

Rational&
Rational::operator-=(const Rational& r)
{
        m_numerator   = m_numerator * r.m_denominator - r.m_numerator * m_denominator;
        m_denominator = m_denominator * r.m_denominator;
        return *this;
}

Rational&
Rational::operator*=(const Rational& r)
{
        m_numerator   *= r.m_numerator;
        m_denominator *= r.m_denominator;
        return *this;
}

Rational&
Rational::operator/=(const Rational& r)
{
        m_numerator   *= r.m_denominator;
        m_denominator *= r.m_numerator;
        return *this;
}

Rational&
Rational::operator++()
{
        m_numerator += m_denominator;
        return *this;
}

const Rational
Rational::operator++(int)
{
        auto copy {*this};
        ++(*this);
        return copy; /* Returns the unincremented copy. */
}

Rational&
Rational::operator--()
{
        m_numerator -= m_denominator;
        return *this;
}

const Rational
Rational::operator--(int)
{
        auto copy {*this};
        --(*this);
        return copy; /* Returns the unincremented copy. */
}

std::ostream&
operator<<(std::ostream& stream, const Rational& r)
{
        return (
                stream
                << r.getNumerator() << " / " << r.getDenominator()
        );
}
