#ifndef PAIR_H
#define PAIR_H

#include <compare>

template<typename FirstValue, typename SecondValue>
class Pair
{
public:
        Pair() = default;
        Pair(FirstValue first_value, SecondValue second_value)
                : first {first_value}, second {second_value}
        {}

        std::partial_ordering operator<=>(const Pair& pair) const
        {
                auto result { first <=> pair.first };
                if (std::is_eq(result))
                        return second <=> pair.second;
                return result;
        }

        bool operator==(const Pair& pair) const
        {
                return ((first == pair.first) && (second == pair.second));
        }

        FirstValue first;
        SecondValue second;
};

#endif
