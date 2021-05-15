#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <string>

template <typename T>
class Array
{
public:
        Array()
                : m_elements {nullptr}, m_size {0}
        {}

        explicit Array(size_t size)
                : m_elements { new T[size] },
                m_size {size}
        {}

        explicit Array(std::initializer_list<T> init_list)
                : m_size {init_list.size()},
                m_elements { new T[init_list.size()] }
        {
                size_t i {};
                for (auto& item : init_list)
                        m_elements[i++] = item;
        }

        /* I've not been able to implement the copy constructor yet... */
        Array(const Array& src) = delete;

        ~Array<T>() { delete[] m_elements; }

        void forEach(size_t perline = 5) const noexcept
        {
                size_t count {};
                for (size_t i {}; i < m_size; ++i) {
                        std::cout << m_elements[i] << ' ';
                        if (! (++count) % perline) std::cout << std::endl;
                }
                std::cout << std::endl;
        }

        T* get()
        {
                T* copy { m_elements };
                delete [] m_elements;
                m_elements = nullptr;
                return copy;
        }

        size_t size() const noexcept { return m_size; }
        T begin() const noexcept { return m_elements[0]; }
        T end() const noexcept { return m_elements[m_size - 1]; }

        T& at(size_t index)
        {
                if (index < 0 || index >= m_size)
                        throw std::out_of_range { "There's no " + std::to_string(index) + " item." };
                return m_elements[index];
        }

        const T& at(size_t index) const { return at(index); }
        T& operator[](size_t index) { return at(index); }
        const T& operator[](size_t index) const { return at(index); }

        void push_back(T item)
        {
                T* new_array { new T[(m_size * sizeof(T)) + sizeof(item)] };
                size_t i;
                for (i = 0; i < m_size; ++i)
                        new_array[i] = at(i);
                new_array[i] = item;
                delete[] m_elements;
                m_elements = new_array;
                ++m_size;
        }

        void push_front(T item)
        {
                T* new_array { new T[(m_size * sizeof(T)) + sizeof(item)] };
                size_t i {};
                new_array[i] = item;
                for (i = 1; i <= m_size; ++i)
                        new_array[i] = at(i - 1);
                delete[] m_elements;
                m_elements = new_array;
                ++m_size;
        }
private:
        T* m_elements;
        size_t m_size;
};

int
main()
{
        Array<int> arr {1, 2, 3};

        std::cout << "Original array:\n";
        arr.forEach();

        arr.push_back(4);
        std::cout << "After adding an item at the end:\n";
        arr.forEach();

        arr.push_front(0);
        std::cout << "After adding an item at the beginning:\n";
        arr.forEach();
}
