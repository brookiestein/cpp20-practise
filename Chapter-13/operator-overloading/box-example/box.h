#ifndef BOX_H
#define BOX_H

class Box
{
        public:
                Box();
                Box(double length, double width, double height);

                double getLength() const;
                double getWidth() const;
                double getHeight() const;
                double getVolume() const;
                bool operator < (const Box& box) const;
                bool operator < (double value) const;

        private:
                double m_length {1.0};
                double m_width  {1.0};
                double m_height {1.0};
};

bool operator < (double value, const Box& box2);

#endif
