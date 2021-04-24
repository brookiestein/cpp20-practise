#ifndef RATIONAL_H
#define RATIONAL_H

#include <ostream>

class Rational
{
        public:
                Rational(int numerator, int denominator);

                /* Accessors */
                int getNumerator() const;
                int getDenominator() const;

                /* Mutators */
                void setNumerator(int numerator);
                void setDenominator(int denominator);

                /* Cast a Rational object to either double or float. */
                explicit operator double() const;
                explicit operator float() const;

                /* Add full support for comparing. */
                auto operator==(const Rational& r) const;
                auto operator==(double number) const;
                auto operator<=>(const Rational& r) const;
                auto operator<=>(double number) const;

                /* TODO */
                /* Arithmetic support for Rational objects. */
                Rational operator-() const;

                // A Rational is false if and only if its numerator equals zero.
                // Note: for operator bool(), we used explicit here to sidestep
                // ambiguities with other operators.
                // We did not add operator!,
                // because this conversion operator covers all use in Boolean expressions
                explicit operator bool() const;

                /* Compound assignment operators. */
                Rational& operator-=(const Rational& r);
                Rational& operator+=(const Rational& r);
                Rational& operator*=(const Rational& r);
                Rational& operator/=(const Rational& r);

                /* Prefix and postfix increment and decrement operators. */
                Rational& operator++();
                const Rational operator++(int);
                Rational& operator--();
                const Rational operator--(int);

        private:
                int m_numerator, m_denominator;
};

std::ostream& operator<<(std::ostream& stream, const Rational& r);
// Binary arithmetic operators: non-member functions to allow for implicit conversions
// This allows expressions such as 2 * (myRationale + 1)
Rational operator+(const Rational& one, const Rational& other);
Rational operator-(const Rational& one, const Rational& other);
Rational operator*(const Rational& one, const Rational& other);
Rational operator/(const Rational& one, const Rational& other);

#endif
