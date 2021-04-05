/* Exercise 10-1. In C++17, the Standard Library <algorithm> module gained the handy */
/* std::clamp() function template. The expression clamp(a,b,c) is used to clamp the value a */
/* to a given closed interval [ b , c ]. That is, if a is less than b , the result of the expression will be */
/* b ; and if a is greater than c , the result will be c ; otherwise a lies within the interval [ b , c ] and */
/* clamp() simply returns a . Write your own my_clamp() function template and try it with a little */
/* test program. */

#include <iostream>

template <typename ReturnType, typename T1, typename T2, typename T3>
ReturnType my_clamp(const T1& a, const T2& b, const T3& c);

/* When requiring template argument deduction, you can't use a function prototype.
 * You must put the entire function just before main() */
/* const auto& */
/* my_clamp(const auto& a, const auto& b, const auto& c) */
/* { */
/*         if (a < b) */
/*                 return b; */
/*         if (a > c) */
/*                 return c; */
/*         return a; */
/* } */

int
main()
{
        int a {2}, b {2}, c {3};
        std::cout << my_clamp<int>(a, b, c) << std::endl;
}

template <typename ReturnType, typename T1, typename T2, typename T3>
ReturnType my_clamp(const T1& a, const T2& b, const T3& c)
{
        if (a < b)
                return b;
        if (a > c)
                return c;
        return a;
}
