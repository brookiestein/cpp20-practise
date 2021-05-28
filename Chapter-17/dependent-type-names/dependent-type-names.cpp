#include <iostream>

template <typename T>
class Base
{
public:
        explicit Base(T value)
                : m_value(value)
        {}

        void baseFun() { std::cout << "baseFun()" << std::endl; }
private:
        T m_value;
};

template <typename T>
class Derived : public Base<T>
{
public:
        explicit Derived(T value)
                : Base<T> {value}
        {}

        void derivedFun()
        {
                std::cout << "derivedFun()" << std::endl;
                Base<T>::baseFun();
        }
};

int
main()
{
        Base<int>* base = new Derived<int>(10);
        static_cast<Derived<int>&>(*base).derivedFun();
}
