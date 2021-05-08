#ifndef TROUBLES_H
#define TROUBLES_H

#include <string>
#include <string_view>

class Trouble
{
public:
        explicit Trouble(std::string_view message = "There's a trouble.")
                : m_message {message}
        {}

        virtual ~Trouble() = default;
        virtual std::string what() const { return m_message; }

private:
        const std::string m_message;
};

class MoreTrouble : public Trouble
{
public:
        explicit MoreTrouble(std::string_view message = "There's more trouble.")
                : Trouble {message}
        {}
};

class BigTrouble : public MoreTrouble
{
public:
        explicit BigTrouble(std::string_view message = "There's a big trouble.")
                : MoreTrouble {message}
        {}
};

#endif
