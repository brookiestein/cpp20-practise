/* Exercise 15-4. Add a function herd() to the Zoo class you made for Exercises 15-2 or */
/* 15-3 that returns a vector<Sheep*> with pointers to all Sheep in the Zoo . The Sheep */
/* remain part of the Zoo . Define a function called shear() for Sheep that removes their */
/* wool. The function returns the weight of the wool after correctly adjusting the weight */
/* members of the Sheep object. Adjust the program of Exercise 15-2 so that it gathers */
/* all Sheep using herd() , collects all their wool, and then outputs information in the Zoo */
/* again. */
/* Hint: To extract an Animal* pointer from a given shared_ptr<Animal> , you call the */
/* get() function of the std::shared_ptr<> template. */
/* Extra: In this chapter, you learned about two different language mechanisms that could */
/* be used to herd() Sheep , that is, two techniques to differentiate Sheep* from other */
/* Animal* pointers. Try both (leaving one commented out). */

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <random>
#include <functional>

#include "dog.h"
#include "sheep.h"
#include "cow.h"
#include "zoo.h"

static auto
createUniformPseudoRandomNumberGenerator(unsigned min, unsigned max)
{
        std::random_device seeder;
        std::default_random_engine generator { seeder() };
        std::uniform_int_distribution distribution { min, max };
        return std::bind(distribution, generator);
}
int
main()
{
        const size_t num_name_options{ 10 };
        using NameOptions = std::vector<std::string>;
        const NameOptions dogNames {
        "Fido", "Rover"  , "Lassie" , "Lambikins",  "Poochy",
        "Spit", "Gnasher", "Samuel" , "Wellington", "Patch"
        };

        const NameOptions sheepNames {
        "Bozo", "Killer", "Tasty", "Pete", "Chops",
        "Blackie", "Whitey", "Eric" , "Sean", "She"
        };

        const NameOptions cowNames {
        "Dolly", "Daisy",   "Shakey", "Amy",   "Dilly",
        "Dizzy", "Eleanor", "Zippy" , "Zappy", "Happy"
        };

        const unsigned minDogWt{ 1 };     // Minimum weight of a dog in pounds
        const unsigned maxDogWt{ 120 };   // Maximum weight of a dog in pounds
        const unsigned minSheepWt{ 80 };  // Minimum weight of a dog in pounds
        const unsigned maxSheepWt{ 150 }; // Maximum weight of a dog in pounds
        const unsigned minCowWt{ 800 };   // Minimum weight of a dog in pounds
        const unsigned maxCowWt{ 1500 };  // Maximum weight of a dog in pounds.

        auto randomAnimalType { createUniformPseudoRandomNumberGenerator(0, 2) }; // 0, 1, or 2
        auto randomNameIndex  { createUniformPseudoRandomNumberGenerator(0, num_name_options - 1) };
        auto randomDogWeight  { createUniformPseudoRandomNumberGenerator(minDogWt, maxDogWt) };
        auto randomSheepWeight{ createUniformPseudoRandomNumberGenerator(minSheepWt, maxSheepWt) };
        auto randomCowWeight  { createUniformPseudoRandomNumberGenerator(minCowWt, maxCowWt) };

        std::vector<std::shared_ptr<Animal>> animals;   // Stores smart pointers to animals
        size_t numAnimals {};             // Number of animals to be created
        std::cout << "How many animals in the zoo? ";
        std::cin >> numAnimals;

        Zoo zoo;                  // Create an empty Zoo

        // Create random animals and add them to the Zoo
        for (size_t i {}; i < numAnimals; ++i) {
                switch (randomAnimalType())
                {
                case 0:                // Create a sheep
                        zoo.addAnimal(std::make_shared<Sheep>(sheepNames[randomNameIndex()], randomSheepWeight()));
                        break;
                case 1:                // Create a dog
                        zoo.addAnimal(std::make_shared<Dog>(dogNames[randomNameIndex()], randomDogWeight()));
                        break;
                case 2:                // Create a cow
                        zoo.addAnimal(std::make_shared<Cow>(cowNames[randomNameIndex()], randomCowWeight()));
                        break;
                }
        }

        zoo.showAnimalsInfo();

        /* Herding sheeps. */
        auto sheeps { zoo.herd() };

        if (sheeps.empty())
                return 0;

        std::vector<double> wools;
        std::cout << "Sheeps:" << std::endl;
        for (const auto& sheep : sheeps) {
                std::cout << sheep->who() << std::endl;
                wools.push_back(sheep->shear());
        }

        std::cout << "\nSheeps' wools:" << std::endl;
        for (const auto& wool : wools)
                std::cout << wool << ", ";
        std::cout << std::endl;
}
