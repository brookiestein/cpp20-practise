#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

class Person
{
        public:
                Person(std::string_view name, const char gender, int age);

                std::string getName() const;
                const char getGender() const;
                int getAge() const;
                void birthday();

        protected:
                const std::string m_name;
                const char m_gender;
                int m_age;
};

#endif
