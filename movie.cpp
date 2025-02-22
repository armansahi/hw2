#include "movie.h"
#include <sstream> 

using namespace std;

// Constructor initializing the movie with specific attributes
Movie::Movie(const string name, double price, int qty, const string genre, const string rating) 
: Product("movie", name, price, qty), genre_(genre), rating_(rating) {
}

// Empty destructor as no dynamic allocation is used
Movie::~Movie() {
}

// Returns a set of keywords including the name and genre
set<string> Movie::keywords() const {
    set<string> keywords = parseStringToWords(name_); // Extract words from the movie name
    keywords.insert(convToLower(genre_)); // Convert genre to lower case and insert into keywords
    return keywords;
}

// Generates string representation of the movie
string Movie::displayString() const {
    stringstream ss;
    ss << name_ << "\nGenre: " << genre_ << " Rating: " << rating_ << "\n" << price_ << " " << qty_ << " left."; 

    return ss.str();
}

// Outputs the movie details
void Movie::dump(ostream& os) const {
    os << "movie\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
  
}
