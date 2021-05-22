/* Default values for template arguments work in a similar way than these
 * of functions. */

#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>

template <typename T = int, int startIndex = 0>
class Array
{
public:
        explicit Array(size_t size)
                : m_size {size},
                m_elements {new T[size]}
        {
                log("Constructor");
        }

        Array(const Array& src)
                : Array {src.m_size}
        {
                log("Copy constructor");
                for (size_t i {}; i < m_size; ++i)
                        m_elements[i] = src.m_elements[i];
        }

        ~Array()
        {
                log("Destructor");
                delete[] m_elements;
                m_elements = nullptr;
        }

        void forEach(size_t perline = 5) const
        {
                size_t count {};
                for (size_t i {}; i < m_size; ++i)
                        std::cout << (count++ % perline == 0 ? '\n' : ' ')
                                << m_elements[i];
                std::cout << std::endl;
        }

        const T& operator[](int index) const
        {
                log("Subscrit operator");
                if (index < startIndex)
                        throw std::out_of_range {"Index too small: " + std::to_string(index)};
                if (index >= m_size)
                        throw std::out_of_range {"Index too large: " + std::to_string(index)};
                return m_elements[index];
        }

        T& operator[](int index)
        {
                log("Using the const-and-back-again idiom.");
                return const_cast<T&>(std::as_const(*this)[index]);
        }

        Array operator=(const Array& src)
        {
                log("Copy and assignment operator.");
                auto tmp {src};
                std::swap(m_elements, tmp.m_elements);
                std::swap(m_size, tmp.m_size);
                return *this;
        }

        size_t size() const { return m_size; }
private:
        size_t m_size;
        T* m_elements;
        void log(std::string_view message) const { std::cout << "[*] " << message << std::endl; }
};

int
main()
{
        Array<> numbers {5};
        for (size_t i {}; i < numbers.size(); ++i)
                numbers[i] = i + 1;

        auto copy { numbers };
        Array<> copy2 {numbers.size()};
        copy2 = numbers;

        std::cout << "\nNumbers:";
        numbers.forEach();

        std::cout << "\nCopy 1:";
        copy.forEach();

        std::cout << "\nCopy 2:";
        copy2.forEach();

        std::cout << std::endl;
}
