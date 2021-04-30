/* Practising Polymorphism. */
/* In this case I'm going to practise polymorphism with
 * collections, such as std::vector<>. */

#include <iostream>
#include <memory>
#include <vector>

#include "box.h"
#include "carton.h"
#include "though_pack.h"

int
main()
{
        std::vector<std::unique_ptr<Box>> polymorphicBoxes;
        polymorphicBoxes.push_back(std::make_unique<Box>(20.0, 30.0, 40.0));
        polymorphicBoxes.push_back(std::make_unique<Carton>(*polymorphicBoxes.at(0), "Plastic"));
        polymorphicBoxes.push_back(std::make_unique<ThoughPack>(*polymorphicBoxes.at(0)));

        for (const auto& box : polymorphicBoxes)
                box->showVolume();
}
