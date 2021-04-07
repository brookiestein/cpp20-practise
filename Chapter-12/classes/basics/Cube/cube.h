#ifndef CUBE_H
#define CUBE_H

class Cube
{
        public:
                explicit Cube(double side);
                double getVolume();
                bool hasLargerVolumeThan(Cube cube);

        private:
                double m_side {};
};

#endif
