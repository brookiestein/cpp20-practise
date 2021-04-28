/* Exercise 14-4. Define a Person class containing member variables to store a person’s age, */
/* name, and gender. Derive an Employee class from Person that adds a member variable to store */
/* a personnel number. Derive an Executive class from Employee . Each derived class should */
/* define a member function who() that displays information about what it is. Think carefully */
/* about proper data hiding and access specifiers in this exercise. In this particular application, */
/* privacy concerns prohibit the exposure of personal details, except for the information printed by */
/* an object’s who() member. Each class can decide explicitly what to expose there. (Name and */
/* type will do—something like “Fred Smith is an Employee.”) Furthermore, people also aren’t */
/* allowed to change name or gender, but they are allowed to age and have birthdays. Write a */
/* main() function to generate a vector of five executives and a vector of five ordinary employees */
/* and display information about them. In addition, display the information about the executives by */
/* calling the member function inherited from the Employee class. */

#include <iostream>
#include <vector>

#include "employee.h"
#include "executive.h"

int
main()
{
        std::vector<Employee> employees {
                Employee { "Stephany Ferreina", 'F', 26, 12345 },
                Employee { "Karina Gallardo", 'F', 27, 67890 },
                Employee { "Miguel Ángel Ortíz", 'M', 32, 13579 },
                Employee { "Rosa Peralta", 'F', 35, 24680 },
                Employee { "Francisco Peguero", 'M', 31, 35791 } 
        };

        employees[4].birthday(); /* Expects 32 in the last output. */

        std::vector<Executive> executives {
                Executive { "Juan Pérez", 'M', 22, 123789 },
                Executive { "José Antonio Ranchal", 'M', 42, 456987 },
                Executive { "Olegaria de las Nieves", 'F', 46, 898765 },
                Executive { "Fefa Vargas", 'F', 44, 817990 },
                Executive { "Manuel de la Cruz", 'M', 27, 420912 },
        };

        for (const auto& employee : employees)
                employee.who();

        std::cout << std::endl;

        for (const auto& executive : executives)
                executive.who();

        std::cout << std::endl;

        for (const auto& executive : executives)
                executive.Employee::who();
}
