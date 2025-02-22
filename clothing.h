#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"
#include "util.h"
#include <set>
#include <string>

// Clothing class as a product
class Clothing : public Product {
public:
// Constructor
  Clothing(const std::string name, double price, int qty, const std::string size, const std::string brand);
  ~Clothing(); //Destructor

  std::set<std::string> keywords() const;
  std::string displayString() const;
  void dump(std::ostream& os) const;

private:
  std::string size_;
  std::string brand_;
};

#endif

