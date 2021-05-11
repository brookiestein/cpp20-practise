#ifndef CURVE_BALL_H
#define CURVE_BALL_H

#include <stdexcept>

class CurveBall : public std::exception
{
public:
        explicit CurveBall(const char* message);
        virtual ~CurveBall();
        const char* what() const noexcept override;

private:
        const char* m_message;
};

#endif
