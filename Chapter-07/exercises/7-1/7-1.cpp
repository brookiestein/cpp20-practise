/* Write a program that reads and stores the first names of any number of
 * students, along with their grades. Calculate and output the average grade and output the
 * names and grades of all the students in a table with the name and grade for three students
 * on each line.
 */

#include <iostream>
#include <string>
#include <vector>
#include <limits>

int
main(void)
{
        std::vector<std::string> students;
        std::vector<int> grades;
        double average {};
        const unsigned per_line {3};

        while (true) {
                std::cout << "Enter a student's first name, leave it blank to end: ";
                std::string name {};
                std::getline(std::cin, name);
                if (name.empty()) break;

                students.push_back(name);

                int grade;
                while (true) {
                        std::cout << "Enter " << name << "'s grade: ";
                        std::cin >> grade;
                        if (grade > 0 && grade <= 8) {
                                grades.push_back(grade);
                                break;
                        }
                        std::cout << name << "'s grade is not valid." << std::endl;
                }

                average += grade;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (students.size() == 0) {
                std::cout << "There's nothing to do." << std::endl;
                return 0;
        }

        average /= students.size();
        std::cout << "\nThe average grade is " << average << std::endl;

        for (int i {}; i < students.size(); ++i) {
                std::cout << students.at(i) << ": " << grades.at(i) << '\t';
                std::cout << "An exception occurred!" << std::endl;
                if ((i + 1) % per_line == 0) std::cout << std::endl;
        }
        std::cout << std::endl;
}
