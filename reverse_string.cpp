//
// Created by elija on 2/28/2023.
//

#include <iostream>

#include "reverse_string.h"

// Reverse a string by returning a pair of iterators that will iterate backwards though the string
// a reference to a string is passed into the function and a pair of reverse iterators is returned
// the first is the beginning of the reversed string, the second is the end of the reversed string
std::pair<std::string::reverse_iterator, std::string::reverse_iterator> reverse_string::reverse_string_1(std::string &str) {
    return std::make_pair(str.rbegin(), str.rend());
}

// demonstrates the usage of the reverse_string_1 method
void reverse_string::demonstration1() {
    std::string str = "This is not a palindrome!";

    std::pair<std::string::reverse_iterator, std::string::reverse_iterator> pair = this->reverse_string_1(str);
    for (auto it = pair.first; it != pair.second; ++it){
        std::cout << *it;
    }
    std::cout << std::endl << std::endl;
}


// Given any item that has a .begin() and .end() functions that return bidirectional iterators and
// addition oporator overloaded, then the method will return a reversed object of the same type
template<class T>
T reverse_string::reverse_string_2(T itemToReverse) {
    T reversedItem = "";
//    because the iterator begins at the non-valid sentinel at the end of the list, we have to decrement by one initially
    for (typename T::iterator i = itemToReverse.end()-1; i != itemToReverse.begin(); --i) {
        reversedItem += *i;
    }
//    because the iterator ends at the beginning we have to include the beginning spot
    reversedItem += *itemToReverse.begin();
    return reversedItem;
}

void reverse_string::demonstration2() {
    std::string str = "Hello to the best engineers, Software engineers!";

    std::cout << this->reverse_string_2(str) << std::endl << std::endl;
}




