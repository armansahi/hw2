#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include "util.h"
#include <set>
#include <string>

// Defines a Book as type of Product
class Book : public Product {
public: 
// Constructor
  Book(const std::string name, double price, int qty, const std::string isbn, const std::string author);
  ~Book(); // Destructor

  std::set<std::string> keywords() const; // gets keywords for search functionality
  std::string displayString() const; // format book for display
  void dump(std::ostream& os) const; 
  
private:
  std::string isbn_;
  std::string author_;
};

#endif

