#ifndef CARTON_H
#define CARTON_H

#include <string>
#include <string_view>
#include <iostream> /* Although the Box class includes it. */

#include "box.h"

class Carton : private Box
{
        public:
                Carton();
                explicit Carton(std::string_view material);
                Carton(double side, std::string_view material);
                Carton(double length, double width, double height, std::string_view material);

                /* Make the volume() member function accessible from here. */
                using Box::volume;

                /* Accessors */
                std::string getMaterial() const;

        private:
                std::string m_material;
};

#endif
