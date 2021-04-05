/* Making functions with the same name using as example the exercise Ex8_13 */
#include <iostream>
#include <string>
#include <vector>

double largest(const double data[], size_t count);
double largest(const std::vector<double>& data);
int largest(const std::vector<int>& data);
std::string largest(const std::vector<std::string>& words);

int
main(void)
{
        double array[] {1.5, 44.6, 13.7, 3.14, 74.5};
        std::vector<double> data {3.5, 4, 75, 84.3, 99.79, 84.4};
        std::vector<int> numbers {1, 2, 4, 10, 14, 50};
        std::vector<std::string> names {
                "Brayan",
                "Arianna",
                "Pedro",
                "Miguel"
        };

        std::cout << "The largest of array is: " << largest(array, std::size(array)) << std::endl;
        std::cout << "The largest of data is: " << largest(data) << std::endl;
        std::cout << "The largest of numbers is: " << largest(numbers) << std::endl;
        std::cout << "The largest of names is: " << largest(names) << std::endl;
}

double
largest(const double data[], size_t count)
{
        double max {data[0]};
        for (size_t i {}; i < count; ++i)
                if (max < data[i]) max = data[i];
        return max;
}

double
largest(const std::vector<double>& data)
{
        double max {data[0]};
        for (auto value : data)
                if (value > max) max = value;
        return max;
}

int
largest(const std::vector<int>& data)
{
        int max {data[0]};
        for (auto value : data)
                if (max < value) max = value;
        return max;
}

std::string
largest(const std::vector<std::string>& words)
{
        std::string max_word {words[0]};
        for (auto& word : words)
                if (max_word < word) max_word = word;
        return max_word;
}
