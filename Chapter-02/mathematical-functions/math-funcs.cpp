#include <iostream>
#include <cmath>

int
main()
{
        double height {100.0};
        double distance {50.0};
        double toe_to_tip {std::sqrt(std::pow(distance, 2) + std::pow(height, 2))};
        std::cout << "Height: " << height << std::endl;
        std::cout << "Distance: " << distance << std::endl;
        std::cout << "Toe to tip: "<< toe_to_tip << std::endl;
        return 0;
}
