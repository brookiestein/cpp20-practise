#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <iostream> /* For size_t */

class Counter
{
public:
        void operator()() noexcept { ++count; };
        size_t getCount() const noexcept { return count; }
        void reset() noexcept { count = 0;  }
private:
        size_t count {};
};

#endif
