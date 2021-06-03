#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <string_view>
#include <stdexcept>
#include <utility>

template<typename T>
class Array
{
public:
        explicit Array(std::size_t size);
        Array(const Array& src);
        Array(Array&& to_move);
        ~Array();
        Array& operator=(const Array& src);
        Array& operator=(Array&& src);
        void swap(Array& src) noexcept;
        T& operator[](std::size_t index);
        const T& operator[](std::size_t index) const;
        std::size_t size() const noexcept { return m_size; }
        bool elementExistsAt(std::size_t index) const { return index < size(); }
private:
        std::size_t m_size;
        T* m_elements;
        void log(std::string_view message) { std::cout << message << std::endl; }
        static inline std::size_t copies;
};

template <typename T>
Array<T>::Array(std::size_t size)
        : m_size(size),
        m_elements(new T[size])
{}

template <typename T>
Array<T>::Array(const Array& src)
        : Array(src.size())
{
        ++Array<T>::copies;
        log('[' + std::to_string(copies) + "] Array of " + std::to_string(size()) + " elements copied.");
        for (std::size_t i {}; i < size(); ++i)
                m_elements[i] = src.m_elements[i];
}

template <typename T>
Array<T>::Array(Array<T>&& to_move)
        : m_size(to_move.m_size),
        m_elements(to_move.m_elements)
{
        log('[' + std::to_string(++copies) + "] Array of " + std::to_string(size()) + " elements moved.");
        to_move.m_elements = nullptr;
}

template <typename T>
Array<T>::~Array()
{
        delete[] m_elements;
}

template <typename T>
Array<T>&
Array<T>::operator=(Array<T>&& src)
{
        std::cout << "Array of " + std::to_string(size()) + " elements moved. (move assignment)" << std::endl;
        if (&src != this) {
                delete[] m_elements;
                m_size = src.m_size;
                m_elements = src.m_elements;
                src.m_elements = nullptr;
        }
        return *this;
}

template <typename T>
Array<T>&
Array<T>::operator=(const Array<T>& src)
{
        auto copy { src };
        swap(copy);
        return *this;
}

template <typename T>
void
Array<T>::swap(Array<T>& src) noexcept
{
        std::swap(m_elements, src.m_elements);
        std::swap(m_size, src.m_size);
}

template <typename T>
const T&
Array<T>::operator[](std::size_t index) const
{
        if (elementExistsAt(index))
                return m_elements[index];
        throw std::out_of_range { "Index '" + std::to_string(index) + "' too large." };
}

template <typename T>
T&
Array<T>::operator[](std::size_t index)
{
        return const_cast<T&>(std::as_const(*this)[index]);
}

#endif
