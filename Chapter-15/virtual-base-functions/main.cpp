/* Calling the base class version of a virtual member function. */

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
                virtual std::string getInfo() const
                {
                        return m_name + " is " + std::to_string(m_age)
                                + " years old.";
                }

        private:
                const std::string m_name;
                int m_age;
};

class Employee : public Person
{
        public:
                Employee(const Person& data, std::string_view occupation)
                        : Person {data}, m_occupation {occupation}
                {}

                std::string getOccupation() const { return m_occupation; }
                std::string getInfo() const override
                {
                        return Person::getInfo() + '\n' + "And works as " + m_occupation;
                }

        private:
                std::string m_occupation;
};

int
main()
{
        Person p {"Brayan", 19};
        Employee e {p, "Programmer"};

        std::cout << e.getInfo() << std::endl;

        /* This is the same than above, but using the magic of calling
         * the base class version of the member function through an object
         * of a derived class. */
        std::string message { e.Person::getInfo() + " And works as " + e.getOccupation() };
        std::cout << '\n' << message << std::endl; 
}
