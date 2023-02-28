//
// Created by iamze on 12/12/2022.
//

#ifndef CLIENTCPP_FORM_HPP
#define CLIENTCPP_FORM_HPP

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "../Error.hpp"

using namespace std;

class VisitorForm;

class Form {
public:
    virtual operator string() const = 0;
    virtual double aire() const = 0;
    virtual void accept(VisitorForm * vf) = 0;
};

inline ostream& operator<<(ostream &os, const Form &f) {
    return os << (string) f;
}


#endif //CLIENTCPP_FORM_HPP
