/* Testing pure virtual functions. */
#include <iostream>
#include <vector>

#include "box.h"
#include "carton.h"
#include "tough_pack.h"
#include "can.h"

int
main()
{
        Box box {40, 30, 20};
        Can can {10, 3};
        Carton carton {40, 30, 20, "Cardboard"};
        ToughPack tough_pack {40, 30, 20};

        std::vector<const Vessel*> vessels {
                &box, &can, &carton, &tough_pack
        };

        /* To separate between constructors' output and showVolume(). */
        std::cout << std::endl;

        for (const auto& vessel : vessels)
                std::cout << "Volume is: " << vessel->volume() << std::endl;

        /* To separate between showVolume()'s output and destructors ones. */
        std::cout << std::endl;
}
