#include <algorithm>
#include <iostream>
#include <vector>

#include <box.hpp>

int
main()
{
        std::vector boxes {
                Box {1, 2, 3}, Box {5, 2, 3},
                Box {9, 2, 1}, Box {3, 2, 1}
        };

        auto print_result = [&boxes] (auto result) {
                if (result == std::end(boxes))
                        std::cout << "No box found.\n";
                else
                        std::cout << "Found matching box at position " << (result - std::begin(boxes)) << std::endl;
        };

        Box box_to_find {3, 2, 1};
        auto result { std::find(std::begin(boxes), std::end(boxes), box_to_find) };
        print_result(result);

        /* Find a box with a volume larger than that of box_to_find. */
        const auto required_volume { box_to_find.volume() };
        result = std::find_if(
                        std::begin(boxes), std::end(boxes),
                        [required_volume] (const Box& box) {
                                return box > required_volume;
                        });
        print_result(result);
}
