#include <iostream>
#include <string>
#include <vector>

#include "array.hpp"

Array<std::string> buildStringArray(std::size_t size);

int
main()
{
        /* const std::size_t numArrays {10}; */
        /* const std::size_t numStrings {1'000}; */
        /* std::vector<Array<std::string>> vectorOfStrings; */
        /* vectorOfStrings.reserve(numArrays); */

        /* for (std::size_t i {}; i < numArrays; ++i) */
        /*         vectorOfStrings.push_back(buildStringArray(numStrings)); */

        Array<std::string> strings {123};
        strings = buildStringArray(1'000);

        Array<std::string> more_strings {2'000};
        strings = std::move(more_strings);
}

Array<std::string>
buildStringArray(std::size_t size)
{
        Array<std::string> result {size};
        for (std::size_t i {}; i < size; ++i)
                result[i] = "You should learn from your competitor, but never copy. Copy and you die.";
        return result;
}
