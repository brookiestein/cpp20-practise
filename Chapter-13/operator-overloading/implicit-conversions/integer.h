#ifndef INTEGER_H
#define INTEGER_H

#include <ostream>

class Integer
{
        public:
                Integer(int value = 0);
                int getValue() const;
                void setValue(int value);
                Integer operator+(const Integer& theOther);
                Integer operator-(const Integer& theOther);
                Integer operator*(const Integer& theOther);
                Integer operator/(const Integer& theOther);

        private:
                int m_value;
};

std::ostream& operator<<(std::ostream& stream, const Integer& obj);

#endif
