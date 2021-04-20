#include "Truckload.h"

Truckload::Truckload() = default;

Truckload::Truckload(const std::vector<SharedBox>& boxes)
{
        for (const auto& box : boxes)
                addBox(box);
}

Truckload::Truckload(const Truckload& src)
{
        for (Package* pkg {src.m_head}; pkg; pkg = pkg->m_next)
                addBox(pkg->m_box);
}

Truckload::~Truckload() { delete m_head; }

Truckload::Iterator
Truckload::getIterator() const
{
        return Iterator {m_head};
}

void
Truckload::addBox(SharedBox box)
{
        auto package { new Package {box} };
        if (m_tail)
                m_tail->m_next = package;
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
                if (current->m_box == boxToRemove) {
                        if (previous)
                                previous->m_next = current->m_next;

                        if (current == m_head)
                                m_head = current->m_next;
                        if (current == m_tail)
                                m_tail = previous;

                        current->m_next = nullptr;
                        delete current;
                        return true;
                }

                previous = current;
                current  = current->m_next;
        }

        return false;
}

std::ostream&
operator<<(std::ostream& stream, const Truckload& load)
{
        const size_t boxesPerLine {3};
        size_t count {};
        auto iterator { load.getIterator() };

        for (auto box {iterator.getFirstBox()}; box; box = iterator.getNextBox()) {
                stream << '(' << *box << ") ";
                if (! (++count % boxesPerLine)) stream << std::endl;
        }

        if (count % boxesPerLine) stream << std::endl;
        return stream;
}

SharedBox
Truckload::operator[](unsigned index)
{
        unsigned count {};
        for (Package* p {m_head}; p; p = p->m_next) {
                if (count++ == index)
                        return p->m_box;
        }
        return nullptr;
}

Truckload::Package::Package(SharedBox box)
        : m_box {box}, m_next {nullptr}
{}

Truckload::Package::~Package() { delete m_next; }

SharedBox
Truckload::Iterator::getFirstBox()
{
        m_current = m_head;
        return m_current ? m_current->m_box : nullptr;
}

SharedBox
Truckload::Iterator::getNextBox()
{
        if (!m_current)
                return getFirstBox();

        m_current = m_current->m_next;

        return m_current ? m_current->m_box : nullptr;
}
