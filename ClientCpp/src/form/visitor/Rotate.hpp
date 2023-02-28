//
// Created by iamze on 28/02/2023.
//

#ifndef CLIENTCPP_ROTATE_HPP
#define CLIENTCPP_ROTATE_HPP

#pragma once
#include "VisitorForm.hpp"

class Rotate : public VisitorForm{
protected:
    double m_x;
    double m_y;
    double m_rad;

public:
    Rotate(double x, double y, double deg) {
        m_x = x;
        m_y = y;
        m_rad = (PI / 180) * deg;
    }

    virtual void visite(Cross * cross) {

    }

    virtual void visite(Circle * rond) {
        // TODO
    }

    virtual void visite(Rect * rect) {
        // TODO
    }
};


#endif //CLIENTCPP_ROTATE_HPP
