#ifndef STACK_H
#define STACK_H

#include <utility> /* For std::swap */
#include <stdexcept>

template<typename T>
class Stack
{
public:
        Stack();
        ~Stack();
        Stack(const Stack& stack);
        Stack& operator=(const Stack& rhs);
        void swap(Stack& other) noexcept;
        void push(const T& item);
        T pop();
        bool isEmpty() const;
private:
        class Node;

        Node* m_head;
};

template<typename T>
Stack<T>::Stack() = default;

template<typename T>
Stack<T>::~Stack()
{
        while (!isEmpty()) pop();
}

template <typename T>
Stack<T>::Stack(const Stack& stack)
{
        if (stack.m_head) {
                m_head = new Node {*stack.m_head};
                Node* oldNode {stack.m_head};
                Node* newNode {m_head};

                while ((oldNode = oldNode->m_next)) {
                        newNode->m_next = new Node {*oldNode};
                        newNode = newNode->m_next;
                }
        }
}

template<typename T>
bool
Stack<T>::isEmpty() const
{
        return m_head == nullptr;
}

template<typename T>
void
Stack<T>::swap(Stack& other) noexcept
{
        std::swap(m_head, other.m_head);
}

template<typename T>
Stack<T>&
Stack<T>::operator=(const Stack& rhs)
{
        auto copy {rhs}; /* Could go wrong and throw exception! */
        swap(copy); /* noexcept. */
        return *this;
}

template<typename T>
void
Stack<T>::push(const T& item)
{
        Node* node {new Node(item)};
        node->m_next = m_head;
        m_head = node;
}

template<typename T>
T
Stack<T>::pop()
{
        if (isEmpty())
                throw std::logic_error { "Stack empty." };

        auto* next {m_head->m_next};
        T item {m_head->m_item};
        delete m_head;
        m_head = next;
        return item;
}

template <typename T>
class Stack<T>::Node
{
public:
        Node(const T& item)
                : m_item {item},
                m_next(nullptr)
        {}
        T m_item;
        Node* m_next;
};

#endif
