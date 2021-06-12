#ifndef NEAREST_H
#define NEAREST_H

#include <cmath>

class Nearest
{
public:
        Nearest(int value)
                : m_value {value}
        {}
        bool operator()(int x, int y) const noexcept
        {
                return std::abs(x - m_value) < std::abs(y - m_value);
        }
private:
        int m_value;
};

#endif
