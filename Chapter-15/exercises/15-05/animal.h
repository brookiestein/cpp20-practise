#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <string_view>

class Animal
{
        public:
                Animal(std::string_view name, double weight_in_pounds);
                virtual ~Animal();
                virtual std::string who() const;
                virtual std::string sound() const = 0;
                virtual std::string getName() const;
                virtual double getWeight() const;
                void setWeight(double weight);

        private:
                const std::string m_name;
                double m_weight;
};

#endif
