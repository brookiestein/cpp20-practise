/* Exercise 8-6. Implement a program that queries the user for a number of grades. A grade is an */
/* integer number between 0 and 100 (both inclusive). The user can stop at any time by entering a */
/* negative number. Once all grades have been collected, your program is to output the following */
/* statistics: the five highest grades, the five lowest grades, the average grade, the median grade, */
/* and the standard deviation and variance of the grades. Of course, you’re to write a separate */
/* function to compute each of these statistics. Also, you must write the code to print five values */
/* only once. To practice, use arrays to store any five extremes and not, for instance, vector s. */
/* Hint: As a preprocessing step, you should first sort the grades the user enters; you’ll see that */
/* this will make writing the functions to compute the statistics much easier. You can adapt the */
/* quicksort algorithm from Ex8_17 to work with grade numbers. */
/* Caution: Make sure to do something sensible if the user enters less than five or even zero */
/* grades. Anything is fine, as long as it does not crash. */
/* Note: The median is the value that appears in the middle position of a sorted list. If there is */
/* an even number of grades, there obviously is no single middle value—the median is then */
/* defined as the mean of the two middle values. The formulas to compute mean (μ) and standard */
/* The variance is then defined as σ 2 . The <cmath> module of the Standard Library exports */
/* std::sqrt() to compute square roots. */

#include <iostream>
#include <vector>

std::vector<double> get_grades();
void five_highest(const std::vector<double>& grades);
void five_lowest(const std::vector<double>& grades);
void average(const std::vector<double>& grades);
void median(const std::vector<double>& grades);
void standard_derivation_and_variance(const std::vector<double>& grades);

int
main()
{

}

std::vector<double>
get_grades()
{
        std::vector<double> grades {};
        for (;;) {
                double grade {};
                std::cout << "Enter a positive grade number between 0 and 100. "
                        << "A negative to end: ";
                std::cin >> grade;
                if (grade < 0) {
                        break;
                } else if (grade > 100) {
                        std::cout << "It can't be greater than 100." << std::endl;
                } else {
                        grades.push_back(grade);
                }
        }
        return grades;
}
