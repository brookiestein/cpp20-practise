#ifndef TRUCKLOAD_H
#define TRUCKLOAD_H

#include "box.hpp"

#include <memory>
#include <vector>
#include <ostream>

class Truckload
{
public:
  Truckload() = default;            // Default constructor - empty truckload
  Truckload(Box box);         // Constructor - one Box
  Truckload(const std::vector<Box>& boxes);  // Constructor - vector of Boxes
  Truckload(const Truckload& src);  // Copy constructor
  Truckload(Truckload&& src) noexcept;  // Move constructor

  Truckload& operator=(const Truckload& src);  // Copy assignment operator
  Truckload& operator=(Truckload&& src) noexcept;  // Move assignment operator

  void swap(Truckload& other) noexcept;
  void addBox(Box box);       // Add a new Box
  /* Missing to implement a removeBox member function! */
  const Box& operator[](size_t index) const;   // Overloaded subscript operator
  Box& operator[](size_t index);   // Overloaded subscript operator
  friend std::ostream& operator<<(std::ostream& stream, const Truckload& load);

private:
  std::vector<Box> m_boxes;
};

// Optional yet conventional non-member function (forwards to member function)
void swap(Truckload& one, Truckload& other) noexcept;

#endif
