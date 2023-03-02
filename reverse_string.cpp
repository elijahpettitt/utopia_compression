//
// Created by elija on 2/28/2023.
//

#include <iostream>

#include "reverse_string.h"

/***********************************************************************************************************************
 * Method 1
 **********************************************************************************************************************/

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


/***********************************************************************************************************************
 * Method 2
 **********************************************************************************************************************/

// Given any item that has a .begin() and .end() functions that return bidirectional iterators and
// addition operator overloaded, then the method will return a reversed object of the same type
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


/***********************************************************************************************************************
 * Method 3
 **********************************************************************************************************************/

// convert to a vector and then reverse the vector in a recursive tree
std::string reverse_string::reverse_string_3(std::string str) {
    auto *strV = new std::vector<char>(str.begin(), str.end());

    std::vector<char> *strReversedV = recurs_method_3(strV);
    auto reversedStrFinal = std::string(strReversedV->begin(), strReversedV->end());

    delete strV;
    delete strReversedV;
    return reversedStrFinal;
}

// inner recursive function that either returns the vector of length 1 or reverses the order of each reversed
// list returned by both recursive children
// note: valarray
std::vector<char>* reverse_string::recurs_method_3(std::vector<char> *str) {
//    Base case: if length less than 2, return vector
    if (str->size() < 2) {
//        create a new vector such that the vector parameter and return vector can be freed separately
//        by the calling function
        return new std::vector<char>(str->begin(), str->end());
    }
//    else: recurse into each half of the list

//    split list
    int divisionBoundary = str->size()/2;
    auto *firstHalf = new std::vector<char>(str->begin(), str->begin()+divisionBoundary);
    auto *secondHalf = new std::vector<char>(str->begin()+divisionBoundary, str->end());

//    recurse
    std::vector<char> *firstReversed = recurs_method_3(firstHalf);
    std::vector<char> *secondReversed = recurs_method_3(secondHalf);

//    combine halves in reverse order
    secondReversed->insert(secondReversed->end(),firstReversed->begin(), firstReversed->end());

//    free memory
    delete firstHalf;
    delete secondHalf;
    delete firstReversed;

//    return
    return secondReversed;
}

void reverse_string::demonstration3() {
    std::string str = "Recursion plus memory management!";

    std::cout << this->reverse_string_3(str) << std::endl << std::endl;
}


/***********************************************************************************************************************
 * Method 4
 **********************************************************************************************************************/



void reverse_string::reversible_string::reverse() {
    int size = this->size();
    char storageC;
    for (int i = 0; i < size/2; ++i) {
        storageC = this->at(i);
    }
}

void reverse_string::demonstration4() {
    std::string str = "Hello World!";

//    create a reversible string and reverse it
    auto reversibleString = reversible_string(str);
    reversibleString.reverse();

    std::cout << reversibleString << std::endl << std::endl;
}

