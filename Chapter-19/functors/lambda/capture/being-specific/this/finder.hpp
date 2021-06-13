/* Capturing the this pointer. */

#include <iostream>
#include <optional>
#include <vector>
#include <cmath>

#include "optimum.hpp"

class Finder
{
public:
        void setNumberToSearchFor(double number) { m_number_to_search_for = number; }
        double getNumberToSearchFor() const noexcept { return m_number_to_search_for; }
        std::optional<double> findNearer(const std::vector<double>& values) const noexcept
        {
                if (values.empty())
                        return std::nullopt;
                return *findOptimum(values, [this] (int x, int y) {
                        return std::abs(x - m_number_to_search_for) < std::abs(y - m_number_to_search_for);
                });
        }
private:
        double m_number_to_search_for;
};
