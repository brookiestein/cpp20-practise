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
                }

                std::string getName() const { return m_name; }
                unsigned int getAge() const { return m_age; }

        protected:
                const std::string m_name;
                unsigned int m_age;
};

class Worker : public Person
{
        public:
                Worker(std::string_view name, int age, std::string_view occupation)
                        : Person {name, age}, m_occupation {occupation}
                {}

                std::string getOccupation() const { return m_occupation; }
                std::string getFullInfo() const
                {
                        return getName() + " is " + std::to_string(getAge()) + " years old.\n"
                                + "And their work consists in being " + getOccupation();
                }

        protected:
                std::string m_occupation;
};

/* Making a class just to do that is kind of stupid, but it works to practise
 * multiple inheritance. */
class Payable
{
        public:
                Payable(double toPay)
                        : m_toPay {toPay}
                {}

                double getPay() const { return m_toPay; }
                void setPay(double toPay) { m_toPay = toPay; }

        private:
                double m_toPay;
};

/* This class inherits directly from Worker, and Payable, but also
 * inherits *indirectly* from Person, that is Worker's base class. */
class Boss : public Worker, public Payable
{
        public:
                /* At first a Boss has to pay nothing. */
                Boss(std::string_view name, int age)
                        : Worker { name, age, "Boss" }, Payable {0.0}
                {}
};

int
main()
{
        Person normalPerson { "Miguel", 27 };
        Worker worker { "Pedro", 30, "Cleaner" };
        Boss boss { "Juan", 42 }; /* Calls to Worker's constructor, and it calls to Person's constructor. */
        boss.setPay(35'500); /* This method belongs to the Payable class. */

        std::cout << normalPerson.getName() << " is " << normalPerson.getAge() << " years old.\n";
        std::cout << std::endl;
        std::cout << worker.getFullInfo() << std::endl;
        std::cout << std::endl;
        std::cout << boss.Worker::getFullInfo() << std::endl;
        std::cout << std::endl;
        std::cout << boss.getName() << " has to pay " << boss.getPay() << '$' << std::endl;
}
