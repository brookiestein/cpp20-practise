#include "employee.h"

Employee::Employee(std::string_view name, char gender,
                int age, long personnelNumber)
        : Person {name, gender, age}, m_personnelNumber {personnelNumber}
{}

void
Employee::who() const
{
        std::cout << m_name << " who is " << m_age
                << " years old is an employee." << std::endl;
}
