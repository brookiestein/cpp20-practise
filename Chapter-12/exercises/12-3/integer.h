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
                Integer();
                Integer(int value);
                Integer(const Integer& src);

                void setInt(int value);
                int getInt() const;
                /* int compare(const Integer& theOther) const; */
                int compare(Integer theOther) const;
                std::string_view traduce(int value) const;
                Integer& add(int value);
                Integer& subtract(int value);
                Integer& multiply(int value);

        private:
                int core;
};

#endif
