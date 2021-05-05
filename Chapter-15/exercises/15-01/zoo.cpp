#include "zoo.h"

Zoo::Zoo() = default;

void
Zoo::addAnimal(std::shared_ptr<Animal> animal)
{
        animals.push_back(animal);
}

void
Zoo::showAnimalsInfo() const
{
        std::cout << "Animal's info:\n";
        for (const auto& animal : animals)
                std::cout << animal->who() << '\n' << animal->sound() << std::endl;
}
