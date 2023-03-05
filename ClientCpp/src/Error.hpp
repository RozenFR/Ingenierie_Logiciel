//
// Created by iamze on 12/12/2022.
//

#ifndef CLIENTCPP_ERROR_HPP
#define CLIENTCPP_ERROR_HPP

#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
#include <exception>

using namespace std;

/**
 * Class Managing general error
 */
class Error : public exception {
private:
    string m_message;
public:
    explicit Error(string message) : m_message(message) {
    }

    operator string() const {
        ostringstream oss;
        oss << m_message;
        return oss.str();
    }

    virtual const char * what() const noexcept {
        return m_message.c_str();
    }
};

inline ostream& operator<<(ostream& os, const Error& err) {
    return os << (string) err << endl;
}


#endif //CLIENTCPP_ERROR_HPP
