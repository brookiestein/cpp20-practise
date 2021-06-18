/* The LIFO concept stands for the Last element that enters into
 * the container is the First that exits. Indeed, Last-In-First-Out
 * FIFO is the opposite: The First element that enters is also the First
 * that exits.
 */

#include <iostream>
#include <stack> /* LIFO Concept */
#include <queue> /* FIFO Concept */

int
main()
{
        const size_t items {10};
        std::stack<unsigned> lifo;
        for (size_t i {}; i < items; ++i)
                lifo.push(i);

        std::queue<unsigned> fifo;
        for (size_t i {}; i < items; ++i)
                fifo.push(i);

        /* Expect that lifo prints all its elements in reverse order
         * than they were added, and fifo prints them in the same order
         * than they were added. */
        std::cout << "Elements in the stack: ";
        while (!lifo.empty()) {
                /* First accessing to the first element in the container
                 * and then removing it. */
                std::cout << lifo.top() << ' ';
                lifo.pop();
        }

        std::cout << "\nElements in the queue: ";
        while (!fifo.empty()) {
                std::cout << fifo.front() << ' ';
                fifo.pop();
        }

        std::cout << std::endl;
}
