#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include <memory>
#include <iostream>

#include "animal.h"

class Zoo
{
        public:
                Zoo();
                void addAnimal(std::shared_ptr<Animal> animal);
                void showAnimalsInfo() const;

        private:
                std::vector<std::shared_ptr<Animal>> animals;
};

#endif
