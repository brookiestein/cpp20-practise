#include <iostream>

#include "box.h"
#include "carton.h"

int
main()
{
        /* Creating a Box, and two Carton objects. */
        Box box { 12.0, 4.0, 6.0 };
        Carton carton1;
        Carton carton2 { "Solid bleached board" };
        Carton carton3 { 20.5, 14.3, 10.0, "Cardboard" };
        Carton carton4 { 3.5, "PET" };

        std::cout << "\nBox occupies " << sizeof box << " bytes." << std::endl;
        std::cout << "Carton 1 occupies " << sizeof carton1 << " bytes." << std::endl;
        std::cout << "Carton 2 occupies " << sizeof carton2 << " bytes." << std::endl;
        std::cout << "Carton 3 occupies " << sizeof carton3 << " bytes." << std::endl;
        std::cout << "Carton 4 occupies " << sizeof carton4 << " bytes." << std::endl;

        std::cout << "\nBox's volume " << box.volume() << std::endl;
        std::cout << "Carton 1's volume " << carton1.volume() << std::endl;
        std::cout << "Carton 1's material " << carton1.getMaterial() << std::endl;
        std::cout << "Carton 2's volume " << carton2.volume() << std::endl;
        std::cout << "Carton 2's material " << carton2.getMaterial() << std::endl;
        std::cout << "Carton 3's volume " << carton3.volume() << std::endl;
        std::cout << "Carton 3's material " << carton3.getMaterial() << std::endl;
        std::cout << "Carton 4's volume " << carton4.volume() << std::endl;
        std::cout << "Carton 4's material " << carton4.getMaterial() << std::endl;

        /* This version of the example can't use the get{Length,Width,Height}
         * member functions because the derived class has inherited everything of
         * the base class as private, except the volume() member function.
         * If you want to prove this, uncomment the following line. */
        /* std::cout << "Carton 1's length is " << carton1.getLength() << std::endl; */
}
