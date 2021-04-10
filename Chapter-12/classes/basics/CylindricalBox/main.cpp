#include <iostream>
#include <cstdlib>

#include "Cylindrical.h"

static void usage(void);

int
main(int argc, char **argv)
{
        double radius {};
        double height {};
        std::string_view material {};
        std::string_view default_param { "default" };

        if (argv[1] && default_param.compare(argv[1]) == 0) {
                radius = Cylindrical::s_max_radius;
                height = Cylindrical::s_max_height;
                material = Cylindrical::s_default_material;
        } else if (argc < 4) {
                usage();
                return 1;
        } else {
                radius = std::atof(argv[1]);
                height = std::atof(argv[2]);
                material = argv[3];
        }

        Cylindrical cylindrical { radius, height, material };

        std::cout << "The volume is " << cylindrical.getVolume() << std::endl;
}

static void
usage(void)
{
        std::cout << "Usage: ./prog [default] [radius height material]" << std::endl;
}
