#include "integer.h"

#include <iostream>

Integer::Integer()
{
        std::cout << "An Integer object has been created." << std::endl;
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
