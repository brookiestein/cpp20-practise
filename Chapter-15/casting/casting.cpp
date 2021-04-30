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
                virtual std::string getInfo() const
                {
                        return m_name + " is " + std::to_string(m_age) + " years old.";
                }

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
                std::string getInfo() const override
                {
                        return Person::getInfo() + " And works as " + m_occupation + '.';
                }

        private:
                std::string m_occupation;
};

std::ostream&
operator<<(std::ostream& stream, const Employee& e)
{
        return (
                stream
                << e.getInfo()
        );
}

int
main()
{
        Person* p { new Employee { "Brayan", 19, "Programmer" } };
        Employee* e { dynamic_cast<Employee*>(p) };

        if (e)
                std::cout << *e << std::endl;

        /* The following won't work. */
        Person* p2 { new Person { "María", 27 } };
        Employee* e2 { dynamic_cast<Employee*>(p2) };

        if (e2)
                std::cout << *e2 << std::endl;
}
