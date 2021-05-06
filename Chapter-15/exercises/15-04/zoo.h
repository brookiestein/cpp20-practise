#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include <memory>
#include <iostream>
#include <typeinfo>
#include <cstring>

#include "animal.h"
#include "sheep.h" /* For having access to the Sheep type. */

class Zoo
{
        public:
                Zoo();
                void addAnimal(std::shared_ptr<Animal> animal);
                void showAnimalsInfo() const;
                const std::vector<Sheep*> herd() const;

        private:
                std::vector<std::shared_ptr<Animal>> animals;
};

#endif
