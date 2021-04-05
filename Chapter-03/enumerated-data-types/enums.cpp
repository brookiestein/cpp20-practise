#include <iostream>

/* enum class Day {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday}; */

enum class Day {
        Monday,                                 Mon     = Monday,
        Tuesday         = Monday + 2,           Tues    = Tuesday,
        Wednesday       = Tuesday + 2,          Wed     = Wednesday,
        Thursday        = Wednesday + 2,        Thu     = Thursday,
        Friday          = Thursday + 2,         Fri     = Friday,
        Saturday        = Friday + 2,           Sat     = Saturday,
        Sunday          = Saturday + 2,         Sun     = Sunday
};

enum class Punctuation : char {
        Comma = ',',
        Period = '.',
        Exclamation = '!',
        Question = '?'
};

int
main(void)
{
        Day today {Day::Sun};
        Day tomorrow {Day::Mon};

        std::cout << "Today is " << static_cast<int>(today) << std::endl;
        std::cout << "Tomorrow will be " << static_cast<int>(tomorrow) << std::endl;

        std::cout << "The comma symbol is " << static_cast<char>(Punctuation::Comma) << std::endl;
        std::cout << "The exclamation symbol is " << static_cast<char>(Punctuation::Exclamation) << std::endl;
        std::cout << "The period symbol is " << static_cast<char>(Punctuation::Period) << std::endl;
        std::cout << "The question symbol is " << static_cast<char>(Punctuation::Question) << std::endl;
        std::cout << std::endl;

        std::cout << "GCC neither Clang have support for C++20 at all at 2020-12-13"
                << static_cast<char>(Punctuation::Period) << std::endl;

        std::cout << "So, I can't use the std::format() function yet"
                << static_cast<char>(Punctuation::Exclamation) << std::endl;
}
