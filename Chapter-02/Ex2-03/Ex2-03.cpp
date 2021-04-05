#include <iostream>
#include <cmath>

int
main()
{
        const double fish_factor {2.0 / 0.5}; // Area per unit length of fish.
        const double inches_per_foot {12.0};
        double fish_count {};
        double fish_length {};

        std::cout << "Enter the number of fish you want to keep: ";
        std::cin >> fish_count;
        std::cout << "Enter the average fish length in inches: ";
        std::cin >> fish_length;
        fish_length /= inches_per_foot;

        // Calculate the required surface area
        const double pond_area {fish_count * fish_length * fish_factor};
        // Calculate the pond diameter from the area
        const double pond_diameter {2.0 * std::sqrt(pond_area / M_PI)};

        std::cout << "Pond diameter required for " << fish_count
                << " fish is " << pond_diameter << " feet.\n";
        return 0;
}
