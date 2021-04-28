#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <string_view>
#include <iostream>

class Animal
{
        public:
                Animal(std::string_view name, int weight);

        protected:
                void who() const;

        private:
                const std::string m_name;
                int m_weight;
};

#endif
