/* Not allowing a member function to be overriden */

#include <iostream>
#include <string>
#include <string_view>

class Person
{
        public:
                Person(std::string_view name, int age)
                        : m_name {name}, m_age {age}
                {}

                std::string getName() const { return m_name; }
                int getAge() const { return m_age; }
                /* Making this function's signature like this disallows
                 * derived classes to override this member function. */
                /* virtual std::string showPersonsInfo() const final */
                virtual std::string showPersonsInfo() const
                {
                        return m_name + " is " + std::to_string(m_age) +
                                " years old.";
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
                Employee(const Person& data, std::string_view occupation)
                        : Person {data}, m_occupation {occupation}
                {}

                std::string showPersonsInfo() const override
                {
                        return Person::showPersonsInfo() + '\n' +
                                "And works as " + m_occupation;
                }

        private:
                std::string m_occupation;
};

int
main()
{
        Person* viewer {nullptr};
        Person p1 { "Brayan", 19 };
        Employee e1 { p1, "Programmer" };

        viewer = &p1;
        std::cout << viewer->showPersonsInfo() << '\n' << std::endl;

        viewer = &e1;
        std::cout << viewer->showPersonsInfo() << std::endl;
}
