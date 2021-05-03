#ifndef BOX_H
#define BOX_H

#include <iostream>

#include "vessel.h"

class Box : public Vessel
{
        public:
                Box();
                Box(double length, double width, double height);
                virtual ~Box();
                double volume() const override;
                void showVolume() const;
                double getLength() const;
                double getWidth() const;
                double getHeight() const;

        private:
                double m_length;
                double m_width;
                double m_height;
};

#endif
