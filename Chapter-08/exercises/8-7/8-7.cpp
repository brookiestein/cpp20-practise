/* Exercise 8-7. The so-called Fibonacci function is popular among lecturers in computer science */
/* and mathematics for introducing recursion. This function has to compute the n th number from */
/* the famous Fibonacci sequence, named after Italian mathematician Leonardo of Pisa, known */
/* also as Fibonacci. This sequence of positive integer numbers is characterized by the fact that */
/* every number after the first two is the sum of the two preceding ones. For n ≥ 1, the sequence */
/* is defined as follows: */
/* 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181… */
/* For convenience, computer scientists mostly define an additional zeroth Fibonacci number as */
/* zero. Write a function to compute the n th Fibonacci number recursively. Test it with a simple */
/* program that prompts the user for how many numbers should be computed and then prints */
/* them out one by one, each on a different line. */
/* Extra: While the naive recursive version of the Fibonacci function is very elegant—the code */
/* matches nearly verbatim with common mathematical definitions—it is notorious for being */
/* very slow. If you ask the computer to compute, say, 100 Fibonacci numbers, you’ll notice that */
/* it becomes noticeably slower and slower as n becomes larger. Do you think you can rewrite */
/* the function to use a loop instead of recursion? How many numbers can you correctly compute */
/* now? */
/* Hint: In each iteration of the loop, you’ll naturally want to compute a next number. To do this, all */
/* you need are the previous two numbers. So, there should be no need to keep track of the full */
/* sequence in, for instance, a vector<> . */

#include <iostream>

void fibonacci(int n);

int
main()
{
        int n {};
        std::cout << "How many numbers do you like me to compute its fibonacci's series? ";
        std::cin >> n;
        fibonacci(n);
}

void
fibonacci(int n)
{
        unsigned long long x {}, y {1ULL}, z {1ULL};
        std::cout << 1 << std::endl;
        for (int i {}; i < (n - 1); ++i) {
                z = x + y;
                x = y;
                y = z;
                std::cout << z << std::endl;
        }
}
