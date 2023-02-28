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
    Circle(double x, double y, double radius) : m_xCenter(x), m_yCenter(y), m_radius(radius) {
    }

    void setX(double x) {
        m_xCenter = x;
    }

    void setY(double y) {
        m_yCenter = y;
    }

    void setRadius(double r) {
        m_radius = r;
    }

    double getX() {
        return m_xCenter;
    }

    double getY() {
        return m_yCenter;
    }

    double getRadius() {
        return m_radius;
    }

    virtual operator string() const {
        ostringstream oss;
        oss << "circle;";
        oss << "(" << m_xCenter << "," << m_yCenter << ");" << m_radius;
        return oss.str();
    }

    friend bool operator==(Circle &circle, Circle &other) {
        return circle.m_radius == other.m_radius
            && circle.m_yCenter == other.m_yCenter
            && circle.m_xCenter == other.m_xCenter;
    }

    virtual double aire() const {
        return PI * m_radius * m_radius;
    }

    virtual void accept(VisitorForm * vf);
};


#endif //CLIENTCPP_CIRCLE_HPP
