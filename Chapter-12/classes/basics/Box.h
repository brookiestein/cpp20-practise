#ifndef BOX_H
#define BOX_H

class Box
{
        public:
                /* The default constructor here stands for whether I, or another programmmer
                 * wants to make a Box object without specifying its properties at the moment
                 * of instanciating it, but later. They can just instanciate it with the default
                 * values. i.e. 1.0 */
                /* Box() {} /1* Default constructor. *1/ */
                Box(double length = 1.0, double width = 1.0, double height = 1.0);
                double getVolume();
                void setLength(double length);
                void setWidth(double width);
                void setHeight(double height);

        private:
                double m_length {1.0};
                double m_width {1.0};
                double m_height {1.0};
};

#endif
