#ifndef CARTON_H
#define CARTON_H

#include <string>
#include <string_view>
#include <algorithm>

#include "box.h"

class Carton : public Box
{
        public:
                Carton();
                Carton(double l, double w, double h, std::string_view material = "Cardboard");
                Carton(const Box& box, std::string_view material);
                ~Carton();
                std::string getMaterial() const;
                double volume() const override;

        private:
                std::string m_material;
};

#endif
