#include <algorithm>
#include <list>
#include <ranges>
#include <set>
#include <vector>

class MyClass {};

int
main()
{
        /* std::vector<int&> v; */

        /* MyClass one, other; */
        /* auto biggest = std::max(one, other); */

        /* std::set<MyClass> objects; */
        /* objects.insert(MyClass {}); */

        std::list numbers { 4, 1, 3, 2 };
        std::ranges::sort(begin(numbers), end(numbers));
}
