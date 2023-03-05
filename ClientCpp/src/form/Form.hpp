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

/**
 * Main class managing every form\n
 * Can even say it's an interface
 */
class Form {
public:
    /**
     * Abstract method to change a form in a string
     * @return string
     */
    virtual operator string() const = 0;

    /**
     * Abstract method to calculate area of a form
     * @return area of form
     */
    virtual double aire() const = 0;

    /**
     * Abstract Method to copy a form
     * @return copy of form
     */
    virtual Form * copy() const = 0;

    /**
     * Method use with visitor to implement different functionalities
     * @param vf Visitor reprensenting a functionality
     */
    virtual void accept(VisitorForm * vf) = 0;
};

/**
 * Overload of <<
 * @param os ostream
 * @param f form
 * @return ostream of form
 */
inline ostream& operator<<(ostream &os, const Form &f) {
    return os << (string) f;
}


#endif //CLIENTCPP_FORM_HPP
