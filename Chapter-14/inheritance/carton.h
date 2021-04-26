#ifndef CARTON_H
#define CARTON_H

#include <string>
#include <string_view>
#include <iostream> /* Although the Box class includes it. */
#include <ostream>

#include "box.h"

class Carton : private Box
{
        public:
                /* This will cause that Box's constructors be inherited. */
                using Box::Box;
                Carton();
                explicit Carton(std::string_view material);
                Carton(double side, std::string_view material);
                Carton(double length, double width, double height, std::string_view material);
                Carton(const Carton& src);

                /* Make the volume() member function accessible from here. */
                using Box::volume;

                /* Accessors */
                std::string getMaterial() const;

        private:
                std::string m_material;
                /* This will cause that that function can access to the members of this class. */
                friend std::ostream& operator<<(std::ostream&, const Carton&);
};

std::ostream&
operator<<(std::ostream& stream, const Carton& carton);

#endif
