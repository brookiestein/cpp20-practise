#include "Package.h"

Package::Package(SharedBox box)
        : m_box {box}, m_next {nullptr}
{
}

Package::~Package()
{
        delete m_next;
}

SharedBox
Package::getBox() const
{
        return m_box;
}

Package*
Package::getNext()
{
        return m_next;
}

void
Package::setNext(Package *package)
{
        m_next = package;
}
