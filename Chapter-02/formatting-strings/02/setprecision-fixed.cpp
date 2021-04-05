#include <ios>
#include <iostream>
#include <iomanip>

int
main()
{
        double answer {42.10};
        std::cout << "The answer is " << std::setprecision(2)
                << std::fixed << answer << std::endl;
        return 0;
}
