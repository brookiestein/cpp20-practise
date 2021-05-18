#include <iostream>
/* #include <initializer_list> */
#include <stdexcept>
#include <string>
#include <utility>

#include "box.h"

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

        /* FIXME: Having this constructor makes confusion when initializing an Array
         * with an initializer_list and with a fixed size. */
        /* explicit Array(std::initializer_list<T> init_list) */
        /*         : m_size {init_list.size()}, */
        /*         m_elements { new T[init_list.size()] } */
        /* { */
        /*         size_t i {}; */
        /*         for (auto& item : init_list) */
        /*                 m_elements[i++] = item; */
        /* } */

        Array(const Array& src)
                : Array {src.m_size}
        {
                for (size_t i {}; i < m_size; ++i)
                        m_elements[i] = src.m_elements[i];
        }

        ~Array() { delete[] m_elements; }

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

        T& begin() const
        {
                if (m_size == 0)
                        throw std::out_of_range { "Array is empty." };
                return m_elements[0];
        }

        T& end() const
        {
                if (m_size == 0)
                        throw std::out_of_range { "Array is empty." };
                return m_elements[m_size - 1]; }

        T& operator=(const Array& src)
        {
                Array<T> copy { src };
                swap(copy);
                return *this;
        }

        void swap(Array& other) noexcept
        {
                std::swap(m_elements, other.m_elements);
                std::swap(m_size, other.m_size);
        }

        const T& operator[](size_t index) const
        {
                if (index >= m_size)
                        throw std::out_of_range { "Index '" + std::to_string(index) + "' too large." };
                return m_elements[index];
        }

        T& operator[](size_t index) { return const_cast<T&>(std::as_const(*this)[index]); }
        const T& at(size_t index) const { return *this[index]; }
        T& at(size_t index) { return const_cast<T&>(std::as_const(*this)[index]); }

        /* Add an item at the end of the array taking in account that array has enough space for adding it. */
        void add(T item)
        {
                if (position == m_size)
                        throw std::out_of_range {
                                "There's no enough space for adding the new item: "
                                + std::to_string(item)
                        };
                m_elements[position++] = item;
        }

        /* Resets the static counter and so start to add items from the beginning of
         * the array. This *will* cause that items at the current position be replaced! */
        void reset_counter() noexcept { position = 0; }

        void push_back(T item)
        {
                auto new_array { get_reallocated_ptr() };
                size_t i {};
                copy_and_assign(new_array, i, m_size);
                new_array[i] = item;
        }

        void push_front(T item)
        {
                auto new_array { get_reallocated_ptr() };
                size_t i {};
                new_array[i++] = item;
                copy_and_assign(new_array, i, m_size + 1);
                /* Adding an item at the beginning must move the position because
                 * e.g, imagine you have this array: 1, 2, 3. And you add 0 at the
                 * beginning, so it is now: 0, 1, 2, 3. If position were 3, adding
                 * another item with the add() member will replace the quarter item,
                 * but if it's incremented here, it will have 4 as value and no item
                 * will be replaced. */
                ++position;
        }
private:
        T* m_elements;
        size_t m_size;
        size_t position {};

        T* get_reallocated_ptr() const { return new T[(m_size * sizeof(T)) + sizeof(T)]; }

        void copy_and_assign(T*& arr, size_t& where_to_start, const size_t& where_to_finish)
        {
                for (size_t i {}; where_to_start < where_to_finish; ++where_to_start, ++i)
                        arr[where_to_start] = at(i);
                delete [] m_elements;
                m_elements = arr;
                ++m_size;
        }
};

int
main()
{
        try {
                Array<int> integers {5};
                for (size_t i {}; i < integers.size(); ++i)
                        integers[i] = i + 1;

                std::cout << "Sum of pairs:\n";
                for (size_t i {integers.size() - 1}; i >= 0; --i) {
                        std::cout
                                << integers[i] << " + " << integers[i - 1] << " = "
                                << (integers[i] + integers[i - 1]) << std::endl;
                }
        } catch (const std::out_of_range& ex) {
                std::cerr << "Out-of-range exception caught: " << ex.what() << std::endl;
        }

        try {
                Array<Box> boxes {5};
                for (size_t i {}; i <= boxes.size(); ++i)
                        std::cout << "Box's volume is: " << boxes[i].volume() << std::endl;
        } catch (const std::out_of_range& ex) {
                std::cerr << "Out-of-range exception caught: " << ex.what() << std::endl;
        }
}
