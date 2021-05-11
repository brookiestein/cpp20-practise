#ifndef DIMENSION_EXCEPTION_H
#define DIMENSION_EXCEPTION_H

#include <stdexcept>
#include <string>

class DimensionException : public std::out_of_range
{
public:
        explicit DimensionException(double value)
                : m_value {value},
                std::out_of_range {"Zero or negative value: " + std::to_string(value)}
        {}

private:
        double m_value;
};

#endif
