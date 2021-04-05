/* Practising the bubble sort algorithm using a vector<> */

#include <iostream>
#include <vector>

int
main(void)
{
        std::vector<double> numbers;

        for (;;) {
                double n {}; /* Temporarily stores the value which will be then stored in numbers */
                std::cout << "Enter a non-zero value or zero to end: ";
                std::cin >> n;
                if (!n)
                        break;
                numbers.push_back(n);
        }

        if (numbers.empty()) {
                std::cout << "Nothing to sort." << std::endl;
                return 0;
        }

        while (true) {
                bool swapped {};

                for (size_t i {}; i < numbers.size(); ++i) {
                        if (numbers[i] > numbers[i + 1]) {
                                double temp {numbers[i]};
                                numbers[i]      = numbers[i + 1];
                                numbers[i + 1]  = temp;
                                swapped = true;
                        }
                }

                if (!swapped) /* Nothing was sorted. */
                        break;
        }

        std::cout << "Numbers ascendentely sorted:" << std::endl;
        for (auto n : numbers) {
                std::cout << n << " ";
        }
        std::cout << std::endl;
}
