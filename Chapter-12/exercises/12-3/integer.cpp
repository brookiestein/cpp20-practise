#include "integer.h"

#include <iostream>

Integer::Integer()
        : core {}
{
        std::cout << "A new Integer object has been created." << std::endl;
}

Integer::Integer(int value)
        : core {value}
{
        std::cout << "A new Integer object has been created." << std::endl;
}

Integer::Integer(const Integer& src)
        : core {src.core}
{
        std::cout << "An Integer object has been created from another." << std::endl;
}

void
Integer::setInt(int value)
{
        core = value;
}

int
Integer::getInt() const
{
        return core;
}

int
Integer::compare(Integer theOther) const
{
        if (core < theOther.core) return -1;
        if (core == theOther.core) return 0;
        return +1;
}

std::string_view
Integer::traduce(int value) const
{
        std::string_view answers[] {"less", "equals", "greater"};
        if (value < 0) return answers[0];
        if (value == 0) return answers[1];
        return answers[2];
}

Integer&
Integer::add(int value)
{
        std::cout << "Adding " << value << " to " << core << std::endl;
        core += value;
        return *this;
}

Integer&
Integer::subtract(int value)
{
        std::cout << "Subtracting " << value << " to " << core << std::endl;
        core -= value;
        return *this;
}

Integer&
Integer::multiply(int value)
{
        std::cout << "Multiplying " << value << " by " << core << std::endl;
        core *= value;
        return *this;
}
