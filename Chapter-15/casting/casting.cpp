/* Casting a pointer to a base class pointing to an object
 * of a derived class to an object of the derived class. */

#include <iostream>
#include <string>
#include <string_view>
#include <ostream>

class Person
{
        public:
                Person(std::string_view name, int age)
                        : m_name {name}, m_age {age}
                {}
                std::string getName() const { return m_name; }
                int getAge() const { return m_age; }

        protected:
                const std::string m_name;
                int m_age;
};

class Employee : public Person
{
        public:
                Employee(std::string_view name, int age, std::string_view occupation)
                        : Person {name, age}, m_occupation {occupation}
                {}
                Employee(const Person& personsData, std::string_view occupation)
                        : Person {personsData}, m_occupation {occupation}
                {}
                std::string getOccupation() const { return m_occupation; }

        private:
                std::string m_occupation;
};

std::ostream&
operator<<(std::ostream& stream, const Employee& e)
{
        return (
                stream
                << e.getName() << " is "
                << e.getAge() << " years old. And works as "
                << e.getOccupation()
        );
}

int
main()
{
        Person* p { new Employee {
                "Brayan",
                19,
                "Programmer"
        }};

        std::cout << *(static_cast<Employee*>(p)) << std::endl;
}
