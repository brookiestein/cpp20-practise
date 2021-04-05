#include <iostream>
#include <limits>

int
main()
{
        std::cout << "The limits for a short variable come from "
                << std::numeric_limits<short>::min() << " to "
                << std::numeric_limits<short>::max() << ".\n";

        std::cout << "The limits for an unsigned int variable come from "
                << std::numeric_limits<unsigned int>::lowest() << " to "
                << std::numeric_limits<unsigned int>::max() << ".\n";

        std::cout << "The limits for an integer variable come from "
                << std::numeric_limits<int>::min() << " to "
                << std::numeric_limits<int>::max() << ".\n";

        std::cout << "The limits for a floating-point float variable come from "
                << std::numeric_limits<float>::lowest() << " to "
                << std::numeric_limits<float>::max() << ".\n";

        std::cout << "The limits for a floating-point double variable come from "
                << std::numeric_limits<double>::lowest() << " to "
                << std::numeric_limits<double>::max() << ".\n";

        return 0;
}
