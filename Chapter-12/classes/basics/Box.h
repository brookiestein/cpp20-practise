#ifndef BOX_H
#define BOX_H

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
                Box(const Box& source); /* A copy constructor */
                /* This kind of functions are called both accesors as getters. */
                double getVolume();
                double getLength() { return m_length; };
                double getWidth() { return m_width; };
                double getHeight() { return m_height; };
                /* These such functions are called both mutators as setters */
                void setLength(double length);
                void setWidth(double width);
                void setHeight(double height);

        private:
                double m_length {1.0};
                double m_width {1.0};
                double m_height {1.0};
};

#endif
