#ifndef CURVE_BALL_H
#define CURVE_BALL_H

#include <stdexcept>
#include <string>
#include <string_view>

class CurveBall : public std::exception
{
public:
        explicit CurveBall(std::string_view message);
        virtual ~CurveBall();
        const char* what() const noexcept override;

private:
        const std::string m_message;
};

#endif
