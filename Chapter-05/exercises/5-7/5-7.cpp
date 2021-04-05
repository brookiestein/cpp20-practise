/* Write a program that will read and store an arbitrary sequence of records
relating to products. Each record includes three items of data—an integer product number,
a quantity, and a unit price. For product number 1001, the quantity is 25 and the unit price is
189Chapter 5 ■ Arrays and Loops
$9.95. Because you do not know yet how to create compound types, simply use three different
array-like sequences to represent these records. The program should output each product
on a separate line and include the total cost. The last line should output the total cost for all
products. Columns should align, so the output should be something like this:

Product Quantity Unit Price  Cost
1001    25            $9.95  $248.75
1003    10            $15.50 $155.00
                             $403.75
 */

#include <iostream>
#include <vector>
#include <cctype>

int
main(void)
{
        std::vector<size_t> product_id;
        std::vector<size_t> quantity;
        std::vector<double> unit_cost;
        char answer {};

        do {
                double id {};
                double q {};
                double cost {};

                std::cout << "Enter a product id, quantity of product and\n"
                        << "unit cost separated by a space: ";
                std::cin >> id >> q >> cost;

                product_id.push_back(static_cast<size_t>(id));
                quantity.push_back(static_cast<size_t>(q));
                unit_cost.push_back(cost);

                std::cout << "Do you want to enter another product [Y/N]? ";
                std::cin >> answer;
        } while (std::tolower(answer) != 'n');

        double total_cost {};
        std::cout << "Product ID\tQuantity\tUnit cost\tCost\n";
        for (size_t i {}; i < product_id.size(); ++i) {
                total_cost += quantity[i] * unit_cost[i];

                std::cout << product_id[i] << "\t\t"
                        << quantity[i] << "\t\t"
                        << unit_cost[i] << "\t\t"
                        << (quantity[i] * unit_cost[i])
                        << std::endl;
        }

        /* I wish I had std::format already :( */
        std::cout << "\t\t\t\t\t\t" << total_cost << std::endl;
}
