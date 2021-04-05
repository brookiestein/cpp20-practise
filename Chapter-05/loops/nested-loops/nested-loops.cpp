#include <iostream>
#include <cctype>

int
main(void)
{
        const size_t table_min {2};
        const size_t table_max {12};
        size_t table {};
        char reply {};

        do {
                std::cout << "What size table would you like "
                        << "(" << table_min << " to " << table_max
                        << ")? ";
                std::cin >> table;

                if (table < table_min || table > table_max) {
                        std::cout << "Invalid table size entered. "
                                << "Program terminated." << std::endl;;
                        return 1;
                }

                /* Create the top line of the table. */
                std::cout << "\t  |";
                for (size_t i {1}; i <= table; ++i) {
                        std::cout << " \t" << i << " |";
                }
                std::cout << std::endl;

                /* Create the separators. */
                for (size_t i {}; i <= table; ++i) {
                        std::cout << "--------";
                }
                std::cout << "--" << std::endl;

                for (size_t i {1}; i <= table; ++i) {
                        /* Iterate over rows. */
                        std::cout << " \t" << i << " |";

                        /* Output the values in a row. */
                        for (size_t j {1}; j <= table; ++j) {
                                std::cout << " \t" << (i * j) << " |";
                        }
                        std::cout << std::endl;
                }

                std::cout << "\nDo you want another table (y or n) ";
                std::cin >> reply;
        } while (std::tolower(reply) == 'y');
}
