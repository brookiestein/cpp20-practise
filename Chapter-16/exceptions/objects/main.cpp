/* Throwing class objects at exception points. */

#include <iostream>
#include <string>
#include <string_view>

class Trouble
{
        public:
                explicit Trouble(std::string_view message = "There was an error.")
                        : m_message {message}
                {
                        std::cout << "Trouble object created." << std::endl;
                }
                ~Trouble() { std::cout << "Trouble object destroyed." << std::endl; }
                std::string what() const { return m_message; }

        private:
                const std::string m_message;
};

void
trySomething(int i)
{
        if (i == 0)
                throw Trouble {};
        else
                throw Trouble { "Nobody knows the trouble I've seen..." };
}

int
main()
{
        for (int i {}; i < 2; ++i) {
                try {
                        trySomething(i);
                } catch (const Trouble& e) {
                        std::cout << e.what() << std::endl;
                }
        }
}
