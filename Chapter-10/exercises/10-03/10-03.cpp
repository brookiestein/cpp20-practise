/* Exercise 10-3. Write a function template called plus() that takes two arguments of potentially */
/* different types and returns a value equal to the sum of both arguments. Next, make sure that */
/* plus() can be used as well to add the values pointed to by two given pointers. */
/* Extra: Can you now make it so that you can also concatenate two string literals using plus() ? */
/* Warning: This may not be as easy as you think! */

#include <iostream>
#include <string>

template <typename ReturnedType, typename T1, typename T2>
ReturnedType plus(T1& arg0, T2& arg1);

template <typename ReturnedType, typename T1, typename T2>
ReturnedType plus(const T1 *arg0, const T2 *arg1);

/* I don't really know whether this can be considered a valid solution! */
std::string plus(const std::string& str0, const std::string& str1);

/* This is allowed starting from C++20 */
/* This is an abbreviated function template. */
/* auto* */
/* plus(const auto* arg0, const auto* arg1) */
/* { */
/*         return *arg0 + *arg1; */
/* } */

int
main()
{
        int n1  = {10};
        int n2  = {20};
        int sum = { plus<int>(n1, n2) };
        std::cout << "The sum of " << n1 << " and " << n2 << " is " << sum << std::endl;

        n1      = n2;
        n2      += n1;
        int another_sum { plus<int>(&n1, &n2) };
        std::cout << "The sum of " << n1 << " and " << n2 << " is " << another_sum << std::endl;

        std::cout << plus("Brayan", " Developer") << std::endl;
}

template <typename ReturnedType, typename T1, typename T2>
ReturnedType plus(T1& arg0, T2& arg1)
{
        return arg0 + arg1;
}

template <typename ReturnedType, typename T1, typename T2>
ReturnedType plus(const T1 *arg0, const T2 *arg1)
{
        return *arg0 + *arg1;
}

std::string
plus(const std::string& str0, const std::string& str1)
{
        return str0 + str1;
}
