/*
 * In this exercise you'll do a program which verify for one's qualification
 * to get a loan, based on whether their age is, at least, 25.
 * Their annual income is, at least $25.000.00 or their bank balance is, at least,
 * 100.000.00.
 * To do this you'll do use of logical operators.
 * Note: The loan, in case of apply, will be either the income square or the bank
 * balance's half based on whether the income square is less than the balance's half or not.
 */
#include <iostream>

int
main(void)
{
        int age {};
        double income {};
        double balance {};

        std::cout << "Please enter your age in years: ";
        std::cin >> age;
        std::cout << "Please enter your annual income in dollars: ";
        std::cin >> income;
        std::cout << "Please enter your bank balance in dollars: ";
        std::cin >> balance;

        if (age >= 25 && (income >= 25'000.00 || balance >= 100'000.00)) {
                int loan {};
                /* Using the conditional operator. */
                loan = income * 2 < balance / 2 ? income * 2 : balance / 2;

                /* Using if-else statement. */
                /* if (income * 2 < balance / 2) { */
                /*         loan = income * 2; */
                /* } else { */
                /*         loan = balance / 2; */
                /* } */

                std::cout << "You can get a loan of $" << loan << std::endl;
        } else {
                std::cout << "Sorry, you don't apply for a loan." << std::endl;
        }
}
