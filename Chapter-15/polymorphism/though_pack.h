#ifndef THOUGH_PACK_H
#define THOUGH_PACK_H

#include "box.h"

class ThoughPack : public Box
{
        public:
                ThoughPack();
                ThoughPack(double length, double width, double height);
                double volume(int i = 500) const;
};

#endif
