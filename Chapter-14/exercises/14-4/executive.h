#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string_view>
#include <iostream>

#include "employee.h"

class Executive : public Employee
{
        public:
                Executive(std::string_view name, char gender,
                        int age, long personnelNumber);
                void who() const;
};

#endif
