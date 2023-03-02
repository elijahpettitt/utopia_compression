#include <iostream>

#include "reverse_string.h"


// Demonstrate all 5 implementations of reversing a string
int main() {


//    Demonstrations
    reverse_string reverseString = reverse_string();


    std::cout << "Reverse a string method 1!" << std::endl;
    reverseString.demonstration1();

    std::cout << "Reverse a string method 2!" << std::endl;
    reverseString.demonstration2();

    std::cout << "Reverse a string method 3!" << std::endl;
    reverseString.demonstration3();

    std::cout << "Reverse a string method 4!" << std::endl;
    reverseString.demonstration4();

    std::cout << "Reverse a string method 5!" << std::endl;
    reverseString.demonstration5();


    std::cout << "\n\nDemonstrations Complete!" << std::endl;
    return 0;
}
