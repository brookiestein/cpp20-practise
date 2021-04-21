#ifndef MESSAGE_H
#define MESSAGE_H

#include <ostream>
#include <cstring>

class Message
{
        public:
                explicit Message(const char* text = "");
                Message(const Message& src);
                ~Message();
                Message& operator=(const Message& right_op);
                Message& operator=(const std::string& src);
                const char* getMessage() const;

        private:
                char* m_message;

};

std::ostream& operator<<(std::ostream& stream, const Message& message);

#endif
