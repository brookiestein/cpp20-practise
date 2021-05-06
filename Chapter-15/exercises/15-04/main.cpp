/* Exercise 15-1. Define a base class called Animal with two member variables: a string */
/* member to store the name of the animal (e.g., "Fido" ) and an integer member, weight , */
/* that will contain the weight of the Animal in pounds. Also include a public member */
/* function, who() , that returns a string object containing the name and weight of the */
/* Animal object, as well as a pure virtual function called sound() that in a derived class */
/* should return a string representing the sound the animal makes. Derive at least three */
/* classes— Sheep , Dog , and Cow —with the class Animal as a public base and implement */
/* the sound() function appropriately in each class. */
/* Define a class called Zoo that can store the addresses of any number of Animal objects */
/* of various types in a vector<> container. Write a main() function to create a random */
/* sequence of an arbitrary number of objects of classes derived from Animal and store */
/* pointers to them in a Zoo object. To keep things simple, work with std::shared_ptr<> */
/* pointers to transfer and store Animal s into the Zoo . (Later, in Chapter 18, we’ll teach */
/* you about move semantics, which will allow you to use unique_ptr<> smart pointers */
/* for this as well.) The number of objects should be entered from the keyboard. Define */
/* a member function of the Zoo class that outputs information about each animal in the zoo,
 * including the text of the sound they all make. */

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
