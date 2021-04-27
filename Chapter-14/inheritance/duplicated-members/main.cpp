#include <iostream>

class Base
{
        public:
                Base(int value = 10)
                        : m_value {value}
                {}

        protected:
                int m_value;
};

class Derived : Base
{
        public:
                Derived(int value = 20)
                        : m_value {value}
                {}

                /* To distinguish the two variables, you must qualify the one
                 * that belongs to the base class, and that that does not have
                 * to be qualified, m_value by itself, refers to the one that
                 * belongs to this same class. */
                int total() const { return m_value + Base::m_value; }

        private:
                int m_value;
};

int
main()
{
        Derived a;
        std::cout << "The total is " << a.total() << std::endl; /* Expects 30. */
}
