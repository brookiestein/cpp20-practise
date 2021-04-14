#ifndef PACKAGE_H
#define PACKAGE_H

#include "SharedBox.h"

class Package
{
        public:
                Package(SharedBox box);
                ~Package();
                /* Retrieve the contained box pointer. */
                SharedBox getBox() const;
                /* Retrieve or update the pointer to the next Package. */
                Package* getNext();
                void setNext(Package* package);

        private:
                /* Pointer to the Box object contained in this Package. */
                SharedBox m_box;
                /* Pointer to the next Package in the list. */
                Package* m_next;
};

#endif
