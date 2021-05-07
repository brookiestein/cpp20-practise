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
        std::cout << "\nAnimal's info:\n";
        for (const auto& animal : animals)
                std::cout << animal->who()
                        << " (" << animal->sound() << ')'
                        << std::endl;
        std::cout << std::endl;
}

const std::vector<std::shared_ptr<Sheep>>
Zoo::herd() const
{
        using SharedSheep = std::vector<std::shared_ptr<Sheep>>;
        SharedSheep tmp;

        for (auto& animal : animals) {
                auto sheep { std::dynamic_pointer_cast<Sheep>(animal) };
                if (sheep)
                        tmp.push_back(sheep);
        }

        /* Yes, copying it, but so taking away the possibility
         * of making sheep mutants :P. */
        const auto sheeps { tmp };
        return sheeps;
}
