#include <iostream>

#include "compute_volume.h"

int
main()
{
        ComputeVolume compute;

        std::cout << "The cubic volume of the room is: "
                << compute(2.0, 2.0, 2.0) << std::endl;
}
