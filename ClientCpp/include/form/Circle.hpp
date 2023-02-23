//
// Created by iamze on 14/12/2022.
//

#ifndef CLIENTCPP_CIRCLE_HPP
#define CLIENTCPP_CIRCLE_HPP

#pragma once
#include "Form.hpp"

#define PI 3.14159265359

class Circle : public Form {
protected:
    double m_xCenter;
    double m_yCenter;
    double m_radius;
public:
    Circle() {

    }

    Circle(double x, double y, double radius) : m_xCenter(x), m_yCenter(y), m_radius(radius) {
    }

    virtual operator string() const {
        ostringstream oss;
        oss << "(" << m_xCenter << ", " << m_yCenter << ");" << m_radius;
        return oss.str();
    }

    virtual double aire() const {
        return PI * m_radius * m_radius;
    }

    virtual void accept(const VisitorForme * vf) const;
};


#endif //CLIENTCPP_CIRCLE_HPP
