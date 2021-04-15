#ifndef INTEGER_H
#define INTEGER_H

#include <string_view>

/* In the first exercise I initialized the only member variable
 * with the curly brace initializer.
 * In this one I'll use the member list initializer.
 */

class Integer
{
        public:
                Integer(int value = 0);
                Integer(const Integer& src);
                ~Integer();

                void setInt(int value);
                int getInt() const;
                /* int compare(const Integer& theOther) const; */
                int compare(Integer theOther) const;
                std::string_view traduce(int value) const;
                static void printCount();

        private:
                int core;
                static inline unsigned int objects {};
};

#endif
