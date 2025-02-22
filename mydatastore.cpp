#include "mydatastore.h"
#include <iostream>

using namespace std;

// Constructor
MyDataStore::MyDataStore() {
}

// Destructor
MyDataStore::~MyDataStore() {
    // Deallocate memory for all products
    for (set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it) {
        delete *it;
    }
    products_.clear();

    // Deallocate memory for all users
    for (map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
        delete it->second;
    }
    users_.clear();
}

void MyDataStore::addProduct(Product* p) { // adds product and indexes by keyword
    products_.insert(p);
    set<string> keywords = p->keywords();
    for (set<string>::iterator it = keywords.begin(); it != keywords.end(); ++it) {
        keywordMap_[*it].insert(p);
    }
}

void MyDataStore::addUser(User* u) { // adds a user to store
    users_[convToLower(u->getName())] = u;
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type) { // search bassed upon specific keywords
    vector<Product*> results;
    if (terms.empty()) {
        return results;
    }

    set<Product*> resultSet;
    for (size_t i = 0; i < terms.size(); i++) {
        string key = convToLower(terms[i]);
        if (keywordMap_.find(key) != keywordMap_.end()) {
            if (i == 0) {
                resultSet = keywordMap_[key];
            } else {
                if (type == 0) { // AND search
                    resultSet = setIntersection(resultSet, keywordMap_[key]);
                } else { // OR search
                    resultSet = setUnion(resultSet, keywordMap_[key]);
                }
            }
        } else if (type == 0) {
            return {}; // If AND search and keyword not found, return empty
        }
    }
    results.assign(resultSet.begin(), resultSet.end());
    return results;
}

void MyDataStore::addToCart(string username, Product* p) { // adds specific product to cart
    username = convToLower(username);
    if (users_.find(username) == users_.end()) {
        cout << "Invalid request" << endl;
        return;
    }
    carts_[username].push_back(p);
}

void MyDataStore::viewCart(string username) { // displays items to cart
    username = convToLower(username);
    if (users_.find(username) == users_.end()) {
        cout << "Invalid username" << endl;
        return;
    }

    deque<Product*>& cart = carts_[username];
    if (cart.empty()) {
        cout << "Cart is empty!" << endl;
        return;
    }

    int index = 1;
    for (deque<Product*>::iterator it = cart.begin(); it != cart.end(); ++it) {
        cout << "Item " << index << ":\n" << (*it)->displayString() << "\n";
        index++;
    }
}

void MyDataStore::buyCart(string username) { // Processes purchases of items in user cart
    username = convToLower(username);
    if (users_.find(username) == users_.end()) {
        cout << "Invalid username" << endl;
        return;
    }

    User* user = users_[username];
    deque<Product*>& cart = carts_[username];
    deque<Product*> remainingItems;

    while (!cart.empty()) {
        Product* p = cart.front(); // get front product
        cart.pop_front();
        // check if can be purchased
        if (p->getQty() > 0 && user->getBalance() >= p->getPrice()) {
            p->subtractQty(1);
            user->deductAmount(p->getPrice());
        } else {
            remainingItems.push_back(p); // add to remaining items if cant be 
        }
    }

    cart = remainingItems;
}

void MyDataStore::dump(ostream& ofile) { // dumps state of store to an output stream
    ofile << "<products>" << endl;
    for (set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it) {
        (*it)->dump(ofile);
    }
    ofile << "</products>" << endl;
    ofile << "<users>" << endl;
    for (map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
        it->second->dump(ofile);
    }
    ofile << "</users>" << endl;
}
