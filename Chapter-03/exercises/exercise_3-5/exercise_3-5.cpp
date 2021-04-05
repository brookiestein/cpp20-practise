/* Write a program that defines an enumeration of type Color where the enumerators
 * are red , green , yellow , purple , blue , black , and white . Define the type for enumerators as
 * an unsigned integer type and arrange for the integer value of each enumerator to be the RGB
 * combination of the color it represents (you can easily find the hexadecimal RGB encoding of any
 * color online). Create variables of type Color initialized with enumerators for yellow, purple, and
 * green. Access the enumerator value and extract and output the RGB components as separate values.
 */

#include <iostream>

enum class Color : unsigned int {
        Red     = 0xFF0000u,
        Green   = 0x00FF00u,
        Yellow  = 0xFFFF00u,
        Purple  = 0xA020F0u,
        Blue    = 0x0000FFu,
        Black   = 0x000000u,
        White   = 0xFFFFFFu
};

int
main(void)
{
        Color yellow {Color::Yellow};
        Color purple {Color::Purple};
        Color green {Color::Green};

        std::cout << "Yellow: "
                << (static_cast<unsigned int>(yellow) & static_cast<unsigned int>(Color::Red) >> 16)
                << (static_cast<unsigned int>(yellow) & static_cast<unsigned int>(Color::Green) >> 8)
                << (static_cast<unsigned int>(yellow) & static_cast<unsigned int>(Color::Blue))
                << std::endl;

        std::cout << "Purple: "
                << (static_cast<unsigned int>(purple) & static_cast<unsigned int>(Color::Red) >> 16)
                << (static_cast<unsigned int>(purple) & static_cast<unsigned int>(Color::Green) >> 8)
                << (static_cast<unsigned int>(purple) & static_cast<unsigned int>(Color::Blue))
                << std::endl;

        std::cout << "Green: "
                << (static_cast<unsigned int>(green) & static_cast<unsigned int>(Color::Red) >> 16)
                << (static_cast<unsigned int>(green) & static_cast<unsigned int>(Color::Green) >> 8)
                << (static_cast<unsigned int>(green) & static_cast<unsigned int>(Color::Blue))
                << std::endl;
}
