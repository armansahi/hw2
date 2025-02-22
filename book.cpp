#include "book.h"
#include <sstream> 

using namespace std;

// Constructor initializing the book with its basic and specific attributes
Book::Book(const string name, double price, int qty, const string isbn, const string author) 
: Product("book", name, price, qty), isbn_(isbn), author_(author) {
}

// Empty destructor as no dynamic allocation is used
Book::~Book() {
}

// Returns a set of keywords including name, author, and ISBN
set<string> Book::keywords() const {
    set<string> keywords = parseStringToWords(name_);
    set<string> authWords = parseStringToWords(author_);
    keywords.insert(authWords.begin(), authWords.end());
    keywords.insert(isbn_);
    return keywords;
}

// Generates a string representation of the book for display
string Book::displayString() const {
    stringstream ss;
    ss << name_ << "\nAuthor: " << author_ << " ISBN: " << isbn_ << "\n" << price_ << " " << qty_ << " left."; 
    return ss.str();
}

// Outputs the book details in a structured format
void Book::dump(ostream& os) const {
    os << "book\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}
