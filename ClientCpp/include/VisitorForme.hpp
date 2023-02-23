//
// Created by iamze on 14/12/2022.
//

#ifndef CLIENTCPP_VISITORFORME_HPP
#define CLIENTCPP_VISITORFORME_HPP

#pragma once
#include <iostream>
#include <string>
#include "form/Cross.hpp"
#include "form/Circle.hpp"
#include "form/Rectangle.hpp"

using namespace std;

class VisitorForme {
public:
    virtual void visite(const Cross * croix) const = 0;
    virtual void visite(const Circle * rond) const = 0;
    virtual void visite(const Rectangle * rond) const = 0;
};


#endif //CLIENTCPP_VISITORFORME_HPP
