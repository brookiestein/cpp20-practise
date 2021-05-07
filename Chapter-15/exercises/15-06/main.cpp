/* Exercise 15-6. Start from the Shape and Circle classes we used earlier to introduce */
/* abstract classes. Create one more Shape derivative, Rectangle , that has a width and */
/* a height. Introduce an extra function called perimeter() that computes a shape’s */
/* perimeter. Define a main() program that starts by filling a polymorphic vector<> with */
/* a number of Shape s (a hard-coded list of Shape s is fine; there’s no need to generate */
/* them randomly). Next, you should print out the total sum of their areas and perimeters, */
/* scale all Shape s with a factor 1.5, and then print out these same sums again. Of course, */
/* you haven’t forgotten what you learned in the first half of this book, so you shouldn’t */
/* put all code inside main() itself. Define the appropriate amount of helper functions! */
/* Hint: For a circle with radius r , the perimeter (or circumference) is computed using the */
/* formula 2π r . */

#include <iostream>
#include <vector>
#include <memory>

#include "circle.h"
#include "rectangle.h"

static auto
sum_areas(const std::vector<Shape*>& shapes)
{
        double total {};
        for (const auto& shape : shapes)
                total += shape->area();
        return total;
}

static auto
sum_perimeters(const std::vector<Shape*>& shapes)
{
        double total {};
        for (const auto& shape : shapes)
                total += shape->perimeter();
        return total;
}

static void
scale_shapes(std::vector<Shape*>& shapes)
{
        for (auto& shape : shapes)
                shape->scale(1.5);
}

int
main()
{
        std::vector<Circle> circles {
                { {0.0, 0.0}, 5.0 },
                { {1.0, 1.0}, 6.0 },
                { {2.0, 2.0}, 7.0 }
        };

        std::vector<Rectangle> rectangles {
                { {3.0, 3.0}, 10.0, 5.0 },
                { {4.0, 4.0}, 20.0, 10.0 },
                { {5.0, 5.0}, 30.0, 15.0 }
        };

        std::vector<Shape*> shapes;

        for (auto& circle : circles)
                shapes.push_back(&circle);

        for (auto& rectangle : rectangles)
                shapes.push_back(&rectangle);

        std::cout << "Shape's area total sum is: " << sum_areas(shapes) << std::endl;
        std::cout << "Shape's perimeter sum is: " << sum_perimeters(shapes) << std::endl;

        scale_shapes(shapes);

        std::cout << "\nShape's area total sum is: " << sum_areas(shapes) << std::endl;
        std::cout << "Shape's perimeter sum is: " << sum_perimeters(shapes) << std::endl;
}
