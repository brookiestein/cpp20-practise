#ifndef ARRAY_H
#define ARRAY_H

#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

template <typename T>
class Array
{
public:
        Array();
        explicit Array(std::size_t size);
        Array(std::initializer_list<T> list);
        Array(const Array& array);
        ~Array();
        void swap(const Array& array) noexcept;
        Array& operator=(const Array& array);
        const T& operator[](std::size_t index) const;
        T& operator[](std::size_t index);
        void push_back(const T& item);
        std::size_t size() const noexcept;
        T end() noexcept;
private:
        std::size_t m_size {};
        T* m_elements {};
};

template<typename T>
Array<T>::Array() = default;

template<typename T>
Array<T>::Array(std::size_t size)
        : m_size(size),
        m_elements(new T[m_size])
{}

template<typename T>
Array<T>::Array(std::initializer_list<T> list)
        : Array (list.size())
{
        /* This syntax of range-based for loop has been introduced in C++ 20. */
        /* So useful when working with initializer_lists. */
        for (std::size_t i {}; T item : list)
                m_elements[i++] = item;
}

template<typename T>
Array<T>::Array(const Array& array)
        : Array (array.m_size)
{
        for (std::size_t i {}; i < array.m_size; ++i)
                m_elements[i] = array.m_elements[i];
}

template<typename T>
Array<T>::~Array()
{
        delete[] m_elements;
        m_elements = nullptr;
}

template<typename T>
void
Array<T>::swap(const Array& array) noexcept
{
        auto copy(array); /* Could go wrong. */
        std::swap(m_elements, copy.m_elements); /* noexcept */
        std::swap(m_size, copy.m_size);
}

template<typename T>
Array<T>&
Array<T>::operator=(const Array& array)
{
        if (m_size == 0)
                throw std::logic_error { "Array empty." };
        swap(array);
        return *this;
}

template<typename T>
const T&
Array<T>::operator[](std::size_t index) const
{
        if (index >= m_size)
                throw std::out_of_range { "Index '" + std::to_string(index) + "' too large." };
        return m_elements[index];
}

template<typename T>
T&
Array<T>::operator[](std::size_t index)
{
        return const_cast<T&>(std::as_const(*this)[index]);
}

template<typename T>
void
Array<T>::push_back(const T& item)
{
        T* elements;
        try {
                elements = new T[m_size + 1];
        } catch (const std::bad_alloc& ex) {
                std::cout << "Error allocating memory for the new item of the Array.\n"
                        << ex.what() << std::endl;
                throw;
        }

        std::size_t i {};
        for (; i < m_size; ++i)
                elements[i] = m_elements[i];
        elements[i] = item;
        delete[] m_elements;
        m_elements = elements;
        ++m_size;
}

template<typename T>
std::size_t
Array<T>::size() const noexcept
{
        return m_size;
}

template<typename T>
T
Array<T>::end() noexcept
{
        return operator[](m_size - 1);
}

#endif
