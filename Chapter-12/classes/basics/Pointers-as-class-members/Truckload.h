#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <vector>

#include "Package.h"

class Truckload
{
        public:
                Truckload();
                Truckload(SharedBox box);
                Truckload(const std::vector<SharedBox>& boxes);
                Truckload(const Truckload& src);

                ~Truckload();

                SharedBox getFirstBox(); /* Get the first Box. */
                SharedBox getNextBox(); /* Get the next Box. */
                void addBox(SharedBox box); /* Add a new Box. */
                bool removeBox(SharedBox box); /* Remove a Box from the Truckload. */
                void listBoxes() const; /* Output the Boxes. */

        private:
                Package* m_head {}; /* First in the list. */
                Package* m_tail {}; /* Last in the list. */
                Package* m_current {}; /* Last retrieved from the list. */
};

#endif
