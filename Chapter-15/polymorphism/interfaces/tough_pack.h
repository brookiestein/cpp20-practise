#ifndef THOUGH_PACK_H
#define THOUGH_PACK_H

#include "box.h"

class ToughPack : public Box
{
        public:
                ToughPack();
                ToughPack(double length, double width, double height);
                ToughPack(const Box& box);
                ~ToughPack();
                double volume() const;
};

#endif
