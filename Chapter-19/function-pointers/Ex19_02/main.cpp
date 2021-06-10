#include <iostream>
#include <string>
#include <vector>

bool less(const int& a, const int& b);
template <typename T> bool greater(const T& a, const T& b);
bool longest(const std::string& a, const std::string& b);
template <typename T> const T* findOptimum(const std::vector<T>& values, bool (*compare)(const T&, const T&));
template <typename T> using Comparison = bool (*)(const T&, const T&);

int
main()
{
        std::vector<int> numbers { 45, 92, 13, 43, 96, 67 };
        std::vector<std::string> names { "Brayan", "Carlos", "Miguel Ángel", "Pedro Enríquez", "Raúl" };
        std::cout << "Minimum number: " << *findOptimum(numbers, less) << std::endl;
        std::cout << "Maximum number: " << *findOptimum(numbers, greater<int>) << std::endl;
        std::cout << "Alphabetically last name: " << *findOptimum(names, greater<std::string>) << std::endl;
        std::cout << "Longest name: " << *findOptimum(names, longest) << std::endl;
}

bool less(const int& a, const int& b) { return a < b; }
template <typename T> bool greater(const T& a, const T& b) { return a > b; }
bool longest(const std::string& a, const std::string& b) { return a.length() > b.length(); }

template <typename T> const T*
findOptimum(const std::vector<T>& values, Comparison<T> compare)
{
        if (values.empty())
                return nullptr;
        const T* optimum { &values[0] };
        for (size_t i {1}; i < values.size(); ++i) {
                if (compare(values[i], *optimum))
                        optimum = &values[i];
        }
        return optimum;
}
