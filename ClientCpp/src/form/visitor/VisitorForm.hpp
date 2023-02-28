//
// Created by iamze on 14/12/2022.
//

#ifndef CLIENTCPP_VISITORFORM_HPP
#define CLIENTCPP_VISITORFORM_HPP

#pragma once
#include <iostream>
#include <string>
#include "../Cross.hpp"
#include "../Circle.hpp"
#include "../Rect.hpp"

using namespace std;

class VisitorForm {
public:
    virtual void visite(Cross * cross) = 0;
    virtual void visite(Circle * rond) = 0;
    virtual void visite(Rect * rect) = 0;
};


#endif //CLIENTCPP_VISITORFORM_HPP
