#include "truckload.hpp"

#include <iostream>
#include <stdexcept>    // For standard exception type std::out_of_range 
#include <string>       // For std::string and std::to_string()
#include <utility>      // For std::swap()

// Constructor - one Box (moved to source file to gain access to definition of Package)
Truckload::Truckload(Box box)
        : m_boxes {box}
{}

// Constructor - vector of Boxes
Truckload::Truckload(const std::vector<Box>& boxes)
{
  for (const auto& box : boxes)
  {
    addBox(box);
  }
}

// Copy constructor
Truckload::Truckload(const Truckload& src)
{
  for (Box box : src.m_boxes)
    addBox(box);
}

// Copy assignment operator (updated to use copy-and-swap of course!)
Truckload& Truckload::operator=(const Truckload& src)
{
  auto copy {src};
  swap(copy);
  return *this;
}

// Move constructor (noexcept!)
Truckload::Truckload(Truckload&& src) noexcept
{
        m_boxes = src.m_boxes;
}

// Move assignment operator (noexcept + move-and-swap of course!)
Truckload& Truckload::operator=(Truckload&& src) noexcept
{
  auto moved {std::move(src)};
  swap(moved);
  return *this;
}

// Swap assignment operator (noexcept + move-and-swap of course!)
void Truckload::swap(Truckload& other) noexcept
{
  std::swap(m_boxes, other.m_boxes);
}

// Optional yet conventional non-member function (forwards to member function)
void swap(Truckload& one, Truckload& other) noexcept
{
  one.swap(other);
}

void Truckload::addBox(Box box)
{
  m_boxes.push_back(box);
}

const Box& Truckload::operator[](size_t index) const
{
  return m_boxes.at(index); /* Using this function to get an exception... */
}

Box&
Truckload::operator[](size_t index)
{
        return const_cast<Box&>(std::as_const(*this)[index]);
}

std::ostream& operator<<(std::ostream& stream, const Truckload& load)
{
  size_t count{};
  for (auto& box : load.m_boxes)
  {
    std::cout << box << ' ';
    if (!(++count % 3))
      std::cout << std::endl;
  }
  if (count % 3) std::cout << std::endl;
  return stream;
}
