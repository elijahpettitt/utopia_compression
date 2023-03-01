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





