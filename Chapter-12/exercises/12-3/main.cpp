#include <iostream>
#include <cmath>

#include "integer.h"

int
main()
{
        /* The operation is: 4 * (5**3) + 6 * (5**2) + 7 * 5 + 8 */
        Integer i1 {4};
        Integer i2 { static_cast<int>(std::pow(5, 3)) };
        Integer i3 {6};
        Integer i4 { static_cast<int>(std::pow(5, 2)) };
        Integer i5 {7};
        Integer i6 {5};
        Integer i7 {8};

        Integer i8 {};

        /* The result, wrongly, has to be: 63293 */
        i8.setInt(
         i1.multiply(i2.getInt())
         .add(i3.getInt())
         .multiply(i4.getInt())
         .add(i5.getInt())
         .multiply(i6.getInt())
         .add(i7.getInt())
         .getInt()
         );

        std::cout << "i8's value is: " << i8.getInt() << std::endl;
}
