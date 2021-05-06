#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <string_view>

class Animal
{
        public:
                Animal(std::string_view name, int weight_in_pounds);
                virtual ~Animal();
                virtual std::string who() const;
                virtual std::string sound() const = 0;
                virtual std::string getName() const;
                virtual int getWeight() const;

        private:
                const std::string m_name;
                int m_weight;
};

#endif
