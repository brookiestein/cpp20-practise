#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include <vector>
#include <ostream>

#include "SharedBox.h"

class Truckload
{
        public:
                Truckload();
                Truckload(SharedBox box);
                Truckload(const std::vector<SharedBox>& boxes);
                Truckload(const Truckload& src);

                ~Truckload();

                class Iterator;
                Iterator getIterator() const;

                void addBox(SharedBox box); /* Add a new Box. */
                bool removeBox(SharedBox box); /* Remove a Box from the Truckload. */
                void listBoxes() const; /* Output the Boxes. */
                SharedBox operator[](unsigned index);

        private:
                class Package;

                Package* m_head {}; /* First in the list. */
                Package* m_tail {}; /* Last in the list. */
};

class Truckload::Iterator
{
        public:
                SharedBox getFirstBox();
                SharedBox getNextBox();

        private:
                Package* m_head;
                Package* m_current;

                friend class Truckload;
                explicit Iterator(Package* head)
                        : m_head {head}, m_current {nullptr} {}
};

class Truckload::Package
{
        public:
                Package(SharedBox box);
                ~Package();

                /* Pointer to the Box object contained in this Package. */
                SharedBox m_box;
                /* Pointer to the next Package in the list. */
                Package* m_next;
};

std::ostream& operator<<(std::ostream& stream, const Truckload& load);

#endif
