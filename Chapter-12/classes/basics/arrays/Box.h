#ifndef BOX_H
#define BOX_H

#include <iostream>

class Box
{
        public:
                /* The default constructor here stands for whether I, or another programmmer
                 * wants to make a Box object without specifying its properties at the moment
                 * of instanciating it, but later. They can just instanciate it with the default
                 * values. i.e. 1.0 */
                Box(); /* Default constructor. */
                Box(double side);
                Box(double length, double width, double height);
                Box(const Box& src); /* A copy constructor */
                /* This kind of functions are called both accesors as getters. */
                double getVolume() const;
                double getLength() const { return m_length; };
                double getWidth() const { return m_width; };
                double getHeight() const { return m_height; };
                size_t getObjectCount() const { return s_object_count; }
                /* These such functions are called both mutators as setters */
                void setLength(double length);
                void setWidth(double width);
                void setHeight(double height);

        private:
                double m_length {1.0};
                double m_width {1.0};
                double m_height {1.0};
                static inline size_t s_object_count {};
};

#endif
