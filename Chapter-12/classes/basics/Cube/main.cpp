#include <iostream>
#include <cstdlib>

#include "cube.h"

static void
usage(void)
{
        std::cout << std::endl;
}

int
main(int argc, char *argv[])
{
        if (argc < 2) {
                usage();
                return 1;
        }

        Cube cube1 { 4.0 };
        Cube cube2 { std::atof(argv[1]) };

        std::cout << "Cube 1's volume is " << cube1.getVolume() << '\n';
        std::cout << "Cube 2's volume is " << cube2.getVolume() << '\n';
        std::cout << "Is Cube 1's volume larger than Cube 2's? "
                << std::boolalpha << cube1.hasLargerVolumeThan(cube2)
                << std::endl;
}
