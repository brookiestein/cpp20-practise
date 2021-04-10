#ifndef CYLINDRICAL_H
#define CYLINDRICAL_H

#include <string>
#include <string_view>

class Cylindrical
{
        public:
                static inline const double s_max_radius { 35.0 };
                static inline const double s_max_height { 60.0 };
                static inline const std::string_view s_default_material { "paperboard" };

                Cylindrical(double radius, double height, std::string_view material = s_default_material);
                double getVolume() const;

        private:
                static inline const double PI { 3.141592 };
                double m_radius {};
                double m_height {};
                std::string m_material {};
};

#endif
