/* Exercise 15-2. Start from the solution of Exercise 15-1. Because Cow s are notoriously */
/* self-conscious about their weight, the result of the who() function of this class must */
/* no longer include the weight of the animal. Sheep , on the other hand, are whimsical */
/* creatures. They tend to prefix their name with "Woolly" —that is, for a Sheep called */
/* "Pete" who() should return a string containing "Woolly Pete" . Besides that, it should */
/* also reflect a Sheep ’s true weight, which is its total weight (as stored in the Animal */
/* base object) minus that of its wool (known by the Sheep itself). Say that a new Sheep ’s */
/* wool by default weighs 10% of his total weight. */

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
}
