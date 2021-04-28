#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string_view>
#include <iostream>

#include "person.h"

class Employee : public Person
{
        public:
                Employee(std::string_view name, char gender, int age, long personnelNumber);
                void who() const;

        private:
                long m_personnelNumber;
};

#endif
