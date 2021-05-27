/* Looking for the differences between parenthesis vs curly brace initializers. */

#include <iostream>
#include <initializer_list>
#include <string_view>
#include <utility>

template <typename T>
class Array
{
public:
        explicit Array(size_t size)
                : m_size(size),
                m_elements(new T[size])
        {}

        Array(std::initializer_list<T> list)
                : Array(list.size())
        {
                for (size_t i {}; T item : list)
                        m_elements[i++] = item;
        }

        Array(const Array& src)
                : Array(src.m_size)
        {
                for (size_t i {}; i < m_size; ++i)
                        m_elements[i] = src.m_elements[i];
        }

        ~Array() { delete[] m_elements; }

        T operator=(const Array& src)
        {
                auto copy {src};
                std::swap(m_elements, copy.m_elements);
                std::swap(m_size, copy.m_size);
                return *this;
        }

        void forEach() const
        {
                for (size_t i {}; i < m_size; ++i)
                        std::cout << m_elements[i]
                                << (i < m_size - 1 ? " " : "\n");
        }
private:
        size_t m_size;
        T* m_elements;
        void log(std::string_view message) { std::cout << message << std::endl; }
};

int
main(void)
{
        Array numbers {1, 2, 3, 4, 5};
        numbers.forEach();
}
