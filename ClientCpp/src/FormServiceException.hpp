//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_FORMSERVICEEXCEPTION_HPP
#define CLIENTCPP_FORMSERVICEEXCEPTION_HPP

#pragma once
#include <string>
#include <ostream>
#include <sstream>
#include <exception>

using namespace std;

class FormServiceException : public exception {
private:
    string m_message;
public:
    explicit FormServiceException(string message) : m_message(message) {
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

inline ostream& operator<<(ostream& os, const FormServiceException& err) {
    return os << (string) err << endl;
}


#endif //CLIENTCPP_FORMSERVICEEXCEPTION_HPP
