#include "person.h"

Person::Person(std::string_view name, const char gender, int age)
        : m_name {name}, m_gender {gender}, m_age {age}
{}

std::string
Person::getName() const { return m_name; }

const char
Person::getGender() const { return m_gender; }

int
Person::getAge() const { return m_age; }

void
Person::birthday() { ++m_age; }
