//
// Created by iamze on 12/12/2022.
//

#ifndef CLIENTCPP_FORM_HPP
#define CLIENTCPP_FORM_HPP

#pragma once
#include "../../../../../../../../../../../../Program Files/mingw64/lib/gcc/x86_64-w64-mingw32/12.2.0/include/c++/iostream"
#include "../../../../../../../../../../../../Program Files/mingw64/lib/gcc/x86_64-w64-mingw32/12.2.0/include/c++/string"
#include "../../../../../../../../../../../../Program Files/mingw64/lib/gcc/x86_64-w64-mingw32/12.2.0/include/c++/sstream"
#include "../Error.hpp"

using namespace std;

class VisitorForme;

class Form {
public:
    virtual operator string() const = 0;
    virtual double aire() const = 0;
    virtual void accept(const VisitorForme * vf) const = 0;
};

inline ostream& operator<<(ostream &os, const Form &f) {
    return os << '(' << (string) f << ')';
}


#endif //CLIENTCPP_FORM_HPP
