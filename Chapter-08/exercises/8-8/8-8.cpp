/* Exercise 8-8. If written using a more mathematical notation, the power() functions we wrote in */
/* Ex8_01 and especially Ex8_16 both essentially compute a power(x,n) for n > 0, as follows: */

/* power(x,n) = x * power(x,n-1) */
/*            = x * (x * power(x,n-2)) */
/*            = ... */
/*            = x * (x * (x * ... (x * x)...))) */

/* Clearly, this method requires exactly n-1 multiplications. It may surprise you, but there is */
/* another, much more effective way. Suppose n is even; then you know the following: */
/* power(x,n) = power(x,n/2) * power(x,n/2) */
/* As both operands of this multiplication are identical, you need to compute this value only once. */
/* That is, you have just reduced the computation of power(x,n) to that of power(x,n/2) , which */
/* obviously at most requires half as many multiplications. Moreover, because you can now apply */
/* this formula recursively, you’ll need even far fewer multiplications than that—only something */
/* in the order of log 2 ( n ) to be exact. To give you an idea, this means that for n in the order of */
/* 1000 , you only need in the order of 10 multiplications! Can you apply this idea to create a more */
/* efficient recursive version of power() ? You can start from the program in Ex8_16.cpp . */
/* Note: This principle is something you’ll often see in recursive algorithms. In each recursive */
/* call, you reduce a problem to a problem of half the size. If you think back, you’ll realize that we */
/* applied the same principle in the quicksort algorithm as well, for instance. Because this solution */
/* strategy is that common, it also has a name; it’s called divide and conquer, after the famous */
/* phrase of Julius Caesar. */

#include <iostream>

long double power(double x, int n);

int
main()
{
        /* Starting from something basic. */
        long double p { power(5.0, 3) };
        std::cout << p << std::endl;
}

long double
power(double x, int n)
{
        if (n == 0)     return 1.0;
        else if (n < 0) return 1.0 / power(x, -n);
        else if (n % 2) return x * power(x, n - 1); /* n is odd. */

        const auto y { power(x, n / 2) };
        return y * y;
}
