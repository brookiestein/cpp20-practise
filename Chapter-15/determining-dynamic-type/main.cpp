/* Determining the dynamic type of some objects. */

#include <iostream>
#include <typeinfo>

#include "box.h"
#include "carton.h"

class NonPolyBase {};
class NonPolyDerived : public NonPolyBase {};

Box& getSomeBox();
NonPolyBase& getSomeNonPoly();

int
main()
{
        std::cout << "Type double has name "
                << typeid(double).name() << std::endl;
        std::cout << "1 is " << (typeid(1) == typeid(int) ? "an int": "no int") << std::endl;

        Carton carton {1, 2, 3, "paperboard"};
        Box& boxReference = carton;

        std::cout << "Type of carton is " << typeid(carton).name() << std::endl;
        std::cout << "Type of boxReference is " << typeid(boxReference).name() << std::endl;
        std::cout << "These are " << (typeid(carton) == typeid(boxReference) ? "" : "not ") << "equal" << std::endl;

        Box* boxPointer = &carton;
        std::cout << "Type of &carton is " << typeid(&carton).name() << std::endl;
        std::cout << "Type of boxPointer is " << typeid(boxPointer).name() << std::endl;
        std::cout << "Type of *boxPointer is " << typeid(*boxPointer).name() << std::endl;

        NonPolyDerived derived;
        NonPolyBase& baseRef = derived;

        std::cout << "Type of baseRef is " << typeid(baseRef).name() << std::endl;

        const auto& type_info1 = typeid(getSomeBox()); /* Function call evaluated. */
        const auto& type_info2 = typeid(getSomeNonPoly()); /* Function call not evaluated. */

        std::cout << "Type of getSomeBox() is " << type_info1.name() << std::endl;
        std::cout << "Type of getSomeNonPoly() is " << type_info2.name() << std::endl;
}

Box&
getSomeBox()
{
        std::cout << "getSomeBox() called..." << std::endl;
        static Carton carton { 2, 3, 5, "duplex" };
        return carton;
}

NonPolyBase&
getSomeNonPoly()
{
        std::cout << "getSomeNonPoly() called..." << std::endl;
        static NonPolyDerived derived;
        return derived;
}
