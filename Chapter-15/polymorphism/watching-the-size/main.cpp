/* Comparing the size of an object of a class that does not have virtual functions
 * with one that does. */

#include <iostream>
#include <string>
#include <string_view>

class Person
{
        public:
                Person(std::string_view name, int age)
                        : m_name {name}, m_age {age}
                {}

                int getAge() const { return m_age; }
                std::string getName() const { return m_name; }
                virtual std::string info() const
                {
                        return m_name + " is " + std::to_string(m_age)
                                + " years old.";
                }

        private:
                const std::string m_name;
                int m_age;
};

/* This class would definitely be perfect to inherit from Person
 * but that's not what I'm looking for.
 * I've even made them almost equal, but with one almost invisible
 * difference, virtual member functions.
 */
class Employee
{
        public:
                Employee(std::string_view name, int age)
                        : m_name {name}, m_age {age}
                {}

                int getAge() const { return m_age; }
                std::string getName() const { return m_name; }
                std::string info() const
                {
                        return m_name + " is " + std::to_string(m_age)
                                + " years old.";
                }

        private:
                const std::string m_name;
                int m_age;
};

int
main()
{
        Person p { "Brayan", 19 };
        Employee e { "Brayan", 19 };

        std::cout << "A Person object's size: " << sizeof(p) << " bytes." << std::endl;
        std::cout << "An Employee object's size: " << sizeof(e) << " bytes." << std::endl;
}
