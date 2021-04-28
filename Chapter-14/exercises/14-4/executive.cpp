#include "executive.h"

Executive::Executive(std::string_view name, char gender,
                int age, long personnelNumber)
        : Employee { name, gender, age, personnelNumber }
{}

void
Executive::who() const
{
        std::cout << m_name << " who is " << m_age
                << " years old is an executive." << std::endl;
}
