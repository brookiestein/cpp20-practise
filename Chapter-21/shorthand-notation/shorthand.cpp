#include <concepts>
#include <iostream>
#include <ostream>

template <typename T>
const T& larger(const T& a, const T& b) requires std::totally_ordered<T>
{
        return a > b ? a : b;
}

class Integer
{
public:
        Integer(int value)
                : m_value (value)
        {}

        int value() const noexcept { return m_value; }

        auto operator<=>(const Integer& other) const noexcept
        {
                return m_value <=> other.m_value;
        }

        auto operator<=>(const int& value) const noexcept
        {
                return m_value <=> value;
        }

        bool operator==(const Integer& other) const noexcept
        {
                return m_value == other.m_value;
        }

        bool operator==(const int& value) const noexcept
        {
                return m_value == value;
        }
private:
        int m_value;
};

std::ostream&
operator<<(std::ostream& out, const Integer& integer)
{
        return out << integer.value();
}

int
main()
{
        std::cout << "Larger between 10 and 15 is: "
                << larger(10, 15) << std::endl;

        /* It is possible to pass an object of the Integer
         * class to the larger() template because it has
         * overloaded all comparison operators, i.e:
         * <, <=, >, >=, ==, !=...
         * So, this class accomplishes what is required by
         * the larger template, its __requires clause__ */
        Integer i1 { 20 };
        Integer i2 { 35 };
        std::cout << "Larger between " << i1.value()
                << " and " << i2.value() << " is: "
                << larger(i1, i2) << std::endl;
}
