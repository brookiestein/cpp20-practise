#include <concepts>
#include <iostream>

template <typename T> requires std::convertible_to<T, int>
class Number
{
public:
        Number(T value)
                : m_value (value)
        {}
        T value() const noexcept { return m_value; }
private:
        T m_value;
};

int
main()
{
        Number number { 3.14 };
        std::cout << "The value is: " << number.value() << std::endl;
}
