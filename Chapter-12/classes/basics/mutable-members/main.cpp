/* A mutable member is that that can be modified even within a
 * const member function. */

#include <iostream>
#include <string>
#include <cstdlib>

static void usage(void);

class Person
{
        public:
                Person(const std::string& name, int age)
                        : m_name {name}
                {
                        if (age > 0)
                                m_age = age;
                }

                /* If a year has passed, this person will celebrate
                 * their birthday, so this function can modify
                 * this person's age even being a const member
                 * function. */
                void hasAYearPassed(bool hasIt) const { if (hasIt) ++m_age; }
                const std::string& getName(void) const { return m_name; }
                const unsigned& getAge(void) const { return m_age; }

        private:
                std::string m_name {};
                mutable unsigned m_age {};
};

int
main(int argc, char **argv)
{
        if (argc < 3) {
                usage();
                return -1;
        }

        const int age { std::atoi(argv[2]) };
        Person user { argv[1], age };
        user.hasAYearPassed(true);
        std::cout << user.getName() << " is "
                << user.getAge() << " years old." << std::endl;
}

static void
usage(void)
{
        std::cout << "Usage: ./prog name age" << std::endl;
}
