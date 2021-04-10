/* Deleting the copy constructor tells the compiler not
 * to create a default one, and, if you've defined one,
 * it also will be deleted. */

#include <iostream>
#include <string>

class Person
{
        public:
                Person(const std::string& name, unsigned age)
                        : m_name {name}, m_age {age}
                {
                }

                Person(const Person& p) = delete;

                std::string getData(void)
                {
                        return m_name + " is "
                                + std::to_string(m_age)
                                + " years old.";
                }

        private:
                std::string m_name;
                unsigned m_age;
};

int
main(void)
{
        Person p1 {"Brayan", 19};
        /* Person p2 {p1}; /1* This shouldn't compile *1/ */

        std::cout << p1.getData() << std::endl;
        /* std::cout << p2.getData() << std::endl; */
}
