/*
 * Write a function, validate_input() , that accepts two integer arguments that
 * represent the upper and lower limits for an integer that is to be entered. It should accept a third
 * argument that is a string describing the input, with the string being used in the prompt for input
 * to be entered. The function should prompt for input of the value within the range specified by
 * the first two arguments and include the string identifying the type of value to be entered. The
 * function should check the input and continue to prompt for input until the value entered by the
 * user is valid. Use the validate_input() function in a program that obtains a user’s date of birth.
 */

#include <iostream>
#include <string>

int validate_input(int lower_limit, int upper_limit,
                const std::string prompt = "Enter an integer number: ");
int day(const std::string prompt = "Enter the day you were born in: ");
int year(const std::string prompt = "Enter the year you were born in: ");
std::string month(const std::string prompt = "Enter the month you were born in: ");

int
main()
{
        int d = day();
        std::string m = month();
        int y = year();

        std::cout << "You were born on " << d << " of " << m << ", " << y << std::endl;
}

int
validate_input(int lower_limit, int upper_limit, const std::string prompt)
{
        while (true) {
                int input {};
                std::cout << prompt;
                std::cin >> input;
                if (input >= lower_limit && input <= upper_limit) return input;
                std::cout << "You must enter a valid number. Valid number is one between "
                        << lower_limit << " and " << upper_limit << '.' << std::endl;
        }
}

int
day(const std::string prompt)
{
        return validate_input(1, 31, prompt);
}

std::string
month(const std::string prompt)
{
        int month = validate_input(1, 12, prompt);
        std::string month_str {};
        switch (month)
        {
        case 1: month_str = "January"; break;
        case 2: month_str = "February"; break;
        case 3: month_str = "March"; break;
        case 4: month_str = "April"; break;
        case 5: month_str = "May"; break;
        case 6: month_str = "Jun"; break;
        case 7: month_str = "July"; break;
        case 8: month_str =  "August"; break;
        case 9: month_str =  "September"; break;
        case 10: month_str = "October"; break;
        case 11: month_str = "November"; break;
        case 12: month_str = "December"; break;
        }
        return month_str;
}

int
year(const std::string prompt)
{
        return validate_input(1950, 2021, prompt);
}
