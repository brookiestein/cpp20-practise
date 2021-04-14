#include "Truckload.h"

Truckload::Truckload() = default;

Truckload::Truckload(const std::vector<SharedBox>& boxes)
{
        for (const auto& box : boxes) {
                addBox(box);
        }
}

Truckload::Truckload(const Truckload& src)
{
        for (Package* pkg {src.m_head}; pkg; pkg = pkg->getNext()) {
                addBox(pkg->getBox());
        }
}

Truckload::~Truckload() { delete m_head; }

SharedBox
Truckload::getFirstBox()
{
        m_current = m_head;
        return m_current ? m_current->getBox() : nullptr;
}

SharedBox
Truckload::getNextBox()
{
        if (!m_current)
                return getFirstBox();

        m_current = m_current->getNext();

        return m_current ? m_current->getBox() : nullptr;
}

void
Truckload::addBox(SharedBox box)
{
        auto package { new Package {box} };
        if (m_tail)
                m_tail->setNext(package);
        else
                m_head = package;
        m_tail = package;
}

bool
Truckload::removeBox(SharedBox boxToRemove)
{
        Package* previous {nullptr};
        Package* current {m_head};

        while (current) {
                if (current->getBox() == boxToRemove) {
                        if (previous)
                                previous->setNext(current->getNext());

                        if (current == m_head)
                                m_head = current->getNext();
                        if (current == m_tail)
                                m_tail = previous;
                        if (current == m_current)
                                m_current = current->getNext();

                        current->setNext(nullptr);
                        delete current;
                        return true;
                }

                previous = current;
                current  = current->getNext();
        }

        return false;
}

void
Truckload::listBoxes() const
{
        const size_t boxesPerLine {4};
        size_t count {};

        for (Package* cp {m_head}; cp; cp = cp->getNext()) {
                std::cout << ' ';
                cp->getBox()->listBox();

                if (! (++count % boxesPerLine)) std::cout << std::endl;
        }

        if (count % boxesPerLine) std::cout << std::endl;
}
