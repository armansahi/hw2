#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "user.h"
# include "product.h"
#include "util.h"
#include <map>
#include <set>
#include <vector>
#include <deque>


class MyDataStore: public DataStore {
public:
  MyDataStore();
  ~MyDataStore();

  void addProduct(Product *p);

  void addUser(User *u);

  std::vector<Product*> search(std::vector<std::string>& terms, int type);

  void addToCart(std::string username, Product *p);

  void viewCart(std::string username);

  void buyCart(std::string username);

  void dump(std::ostream& ofile);

private:
  std::map<std::string, std::set<Product*>> keywordMap_;

  std::map<std::string, User*> users_;

  std::map<std::string, std::deque<Product*>> carts_;

  std::set<Product*> products_;
};

#endif
