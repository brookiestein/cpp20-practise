#include "integer.h"

#include <iostream>

Integer::Integer()
        : core {}
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

/* int */
/* Integer::compare(Integer theOther) const */
/* { */
/*         if (core < theOther.core) return -1; */
/*         if (core == theOther.core) return 0; */
/*         return +1; */
/* } */

int
compare(const Integer& v1, const Integer& v2)
{
        if (v1.core < v2.core) return -1;
        if (v1.core == v2.core) return 0;
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
