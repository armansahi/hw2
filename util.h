#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> interResult; // intersection result
  typename std::set<T>::iterator iter1 = s1.begin(); // Iterator for first set
  typename std::set<T>::iterator iter2 = s2.begin(); // Iterator for second set

  while(iter1 != s1.end() && iter2 != s2.end()) { // Iterate through both sets for common elements
    if(*iter1 < *iter2) {
      iter1++; // advance if first is smaller
    }
    else if (*iter2 < *iter1) {
      iter2++; // advance if second is smaller
    }
    else {
      interResult.insert(*iter1); 
      iter1++; // equal
      iter2++;
    }
  }
  return interResult;
}


template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> unionResult = s1; // all elements from first set
  unionResult.insert(s2.begin(), s2.end()); // insert all from second set
  return unionResult;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;

#endif
