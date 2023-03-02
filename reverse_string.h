//
// Created by elija on 2/28/2023.
//

#ifndef UTOPIACOMPRESSION_REVERSE_STRING_H
#define UTOPIACOMPRESSION_REVERSE_STRING_H

#include <string>
#include <utility>
#include <vector>

// Reverse Strings in 5 different ways, with demonstrations provided.
class reverse_string {
public:
    std::pair<std::string::reverse_iterator, std::string::reverse_iterator> reverse_string_1(std::string &str);
    void demonstration1();

    template<class T>
    T reverse_string_2(T itemToReverse);
    void demonstration2();

    std::string reverse_string_3(std::string str);
    void demonstration3();

    class reversible_string: public std::string {
    public:
        explicit reversible_string(std::string str): std::string(std::move(str)) {}
        void reverse();
        using std::string::operator[];
        using std::string::operator=;
    };
    void demonstration4();

private:
    std::vector<char>* recurs_method_3(std::vector<char> *str);

};


#endif //UTOPIACOMPRESSION_REVERSE_STRING_H
