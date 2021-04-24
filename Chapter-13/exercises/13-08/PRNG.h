#ifndef PRNG_H
#define PRNG_H

class Random
{
        public:
                Random(int n)
                        : m_n {n}
                {}

                int operator()()
                {
                        const int current {m_n};
                        m_n = (m_n * 41 + 7) % 100;
                        return current;
                }

        private:
                int m_n;
};

#endif
