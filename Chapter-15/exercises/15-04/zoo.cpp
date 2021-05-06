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

const std::vector<Sheep*>
Zoo::herd() const
{
        std::vector<Sheep*> tmp;
        const auto sheep_class_value { "5Sheep" }; /* This is the value *my* compiler gives to the Sheep class. */
        for (auto& animal : animals) {
                /* Determining the dynamic type, Sheep, for all animals with dynamic_cast<>. */
                /* Sheep* sheep { dynamic_cast<Sheep*>(animal.get()) }; */
                /* if (sheep) */
                /*         tmp.push_back(sheep); */

                /* Determining the dynamic type, Sheep, for all animals using typeid */
                /* After testing what name the compiler gives to the Sheep class,
                 * this could be determined such as: */

                /* Implicitly converting from const char* to const std::string */
                /* By the way, note how I am dereferencing the pointer got with the get() function.
                 * That will cause that that expression be evaluated, at least if it were passed
                 * directly to the typeid operator just like that. */
                const Animal* an { animal.get() };
                const std::string result { typeid(*an).name() };
                if (result == sheep_class_value) {
                        Sheep* sheep { dynamic_cast<Sheep*>(animal.get()) };
                        tmp.push_back(sheep);
                }

                /* At the end of the day this is almost the same than what's above, but
                 * the only difference is that you can push_back the pointer with confidence because
                 * you already know that it's effectively a pointer-to-Sheep. */
        }

        /* Yes, copying it, but so taking away the possibility
         * of making sheep mutants :P. */
        const auto sheeps { tmp };
        return sheeps;
}
