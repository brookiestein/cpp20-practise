/* 1. A static member function does not belong to any object of the
 * class in which it is declared, but it belongs to the class itself. */
/* 2. Implementing a destructor to decrease the persons static member variable. */

#include <iostream>
#include <string>
#include <string_view>

class Person
{
        public:
                Person(std::string_view name, int age)
                        : m_name {name}
                {
                        m_age = age > 0 ? age : 1;
                        addPerson();
                }

                static unsigned getPersons(void) { return persons; }

                std::string getPersonsData(void) const
                {
                        return m_name + " is " + std::to_string(m_age) + " years old.";
                }

                ~Person() { std::cout << "Deleting person.\n"; --persons; }

        private:
                const std::string m_name {};
                unsigned m_age {};
                static inline unsigned persons;

                static void addPerson(void)
                {
                        ++persons;
                        std::cout << persons
                                << (persons == 1 ? " was " : " were ")
                                << "added." << std::endl;
                }
};

int
main(void)
{
        std::cout << "Starting the program there are "
                << Person::getPersons() << " persons.\n" << std::endl;

        {
                const size_t size {4};
                Person persons[size] {
                        { "Pepe", 27 },
                        { "María", 32 },
                        { "Yahaira", 25 },
                        { "Miguel", 17 }
                };

                std::cout << std::endl;
                for (size_t i {}; i < size; ++i) {
                        std::cout << persons[i].getPersonsData() << std::endl;
                }
        }

        std::cout << '\n' << "At the end of the program there are "
                << Person::getPersons() << " persons." << std::endl;
}
