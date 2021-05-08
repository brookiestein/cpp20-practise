/* Destructors are always noexcept, i.e. they do not propagate exceptions.
 * Instead, std::terminate() is called. Let's prove that! */

#include <iostream>
#include <string>
#include <string_view>
#include <cstring>

class Exception
{
public:
        explicit Exception(std::string_view message = "There was an error.")
                : m_message {message}
        {}

        std::string what() const { return m_message; }

private:
        const std::string m_message;
};

class Person
{
public:
        Person(const char* name, int age)
                : m_age {age}
        {
                m_name = new char[std::strlen(name) + 1];
                std::strncpy(m_name, name, std::strlen(name));
        }

        ~Person()
        {
                /* I don't know if it is because I have not too much experience
                 * treating with exceptions, but this seems me a little bit weird,
                 * throwing an exception with a hard-coded message and then catching it
                 * and showing it through the console. */
                try {
                        delete m_name;
                        throw Exception {"I want to throw an exception because I'm the boos!"};
                } catch (const Exception& ex) {
                        std::cout << ex.what() << std::endl;
                        throw;
                }
        }

        std::string getPersonsInfo() const
        {
                const std::string theName { m_name };
                return theName + " is " + std::to_string(m_age) + " years old.";
        }

private:
        char* m_name;
        int m_age;
};

int
main()
{
        Person p { "Brayan", 19 };
        std::cout << p.getPersonsInfo() << std::endl;
}
