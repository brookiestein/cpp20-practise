#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
        public:
                Integer();

                void setInt(int value);
                int getInt() const;

        private:
                int core {};
};

#endif
