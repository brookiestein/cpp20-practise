#ifndef CAN_H
#define CAN_H

#include <iostream>
#include <cmath>

#include "vessel.h"

class Can : public Vessel
{
        public:
                Can(double diameter, double height);
                ~Can();

                double volume() const override;

        private:
                double m_diameter;
                double m_height;
};

#endif
