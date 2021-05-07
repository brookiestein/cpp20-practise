/* Exercise 15-5. You may have wondered why for the herd() function in Exercise */
/* 15-4 we asked you to switch from using Animal shared_ptr<> s to raw Sheep* */
/* pointers. Shouldn’t that have been shared_ptr<Sheep> instead? The main problem */
/* is that you cannot simply cast a shared_ptr<Animal> to a shared_ptr<Sheep> . */
/* These are unrelated types as far as the compiler is concerned. But you are correct; */
/* it probably would’ve been better to use shared_ptr<Sheep> , and we were probably */
/* underestimating your capabilities there. All you really need to know is that to cast */
/* between shared_ptr<Animal> and shared_ptr<Sheep> you mustn’t use the built-in */
/* dynamic_cast<> and static_cast<> operators, but instead the std::dynamic_ */
/* pointer_cast<> and std::static_pointer_cast<> Standard Library functions */
/* defined in the <memory> module. For instance, let shared_animal be a shared_ */
/* ptr<Animal> . Then dynamic_pointer_cast<Sheep>(shared_animal) results in a */
/* shared_ptr<Sheep> . If shared_animal points to a Sheep , the resulting smart pointer */
/* will refer to that Sheep ; if not, it will contain nullptr . Adapt the solution of Exercise */
/* 15-4 to properly use smart pointers everywhere. */

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
