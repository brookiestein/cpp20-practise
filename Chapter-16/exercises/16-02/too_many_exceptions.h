#ifndef TOO_MANY_EXCEPTIONS_H
#define TOO_MANY_EXCEPTIONS_H

#include <stdexcept>

class TooManyExceptions final : public std::exception
{
public:
        explicit TooManyExceptions(const char* message = "Too many exceptions!");
        const char* what() const noexcept override;
private:
        const char* m_message;
};

#endif
