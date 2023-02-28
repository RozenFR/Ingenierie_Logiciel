//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_RECT_HPP
#define CLIENTCPP_RECT_HPP

#include <ctgmath>

#pragma once
#include "Form.hpp"

class Rect : public Form {
protected:
    double m_x1, m_y1;
    double m_x2, m_y2;
    double m_x3, m_y3;
    double m_x4, m_y4;
public:
    Rect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : m_x1(x1), m_x2(x2), m_x3(x3), m_x4(x4), m_y1(y1), m_y2(y2), m_y3(y3), m_y4(y4) {

    }

    void setX1(double x) {
        m_x1 = x;
    }

    void setY1(double y) {
        m_y1 = y;
    }

    void setX2(double x) {
        m_x2 = x;
    }

    void setY2(double y) {
        m_y2 = y;
    }

    void setX3(double x) {
        m_x3 = x;
    }

    void setY3(double y) {
        m_y3 = y;
    }

    void setX4(double x) {
        m_x4 = x;
    }

    void setY4(double y) {
        m_y4 = y;
    }

    double getX1() const {
        return m_x1;
    }

    double getY1() const {
        return m_y1;
    }

    double getX2() const {
        return m_x2;
    }

    double getY2() const {
        return m_y2;
    }

    double getX3() const {
        return m_x3;
    }

    double getY3() const {
        return m_y3;
    }

    double getX4() const {
        return m_x4;
    }

    double getY4() const {
        return m_y4;
    }

    virtual operator string() const {
        ostringstream oss;
        oss << "rectangle;";
        oss << "(" << m_x1 << ", " << m_y1 << ");";
        oss << "(" << m_x2 << ", " << m_y2 << ");";
        oss << "(" << m_x3 << ", " << m_y3 << ");";
        oss << "(" << m_x4 << ", " << m_y4 << ")";
        return oss.str();
    }

    friend bool operator==(Rect &rect, Rect &other) {
        return rect.m_x1 == other.m_x1
            && rect.m_y1 == other.m_y1
            && rect.m_x2 == other.m_x2
            && rect.m_y2 == other.m_y2
            && rect.m_x3 == other.m_x3
            && rect.m_y3 == other.m_y3
            && rect.m_x4 == other.m_x4
            && rect.m_y4 == other.m_y4;
    }

    virtual double aire() const {
        double vx1 = m_x2 - m_x1; double vy1 = m_y2 - m_y1;
        double vx2 = m_x3 - m_x1; double vy2 = m_y3 - m_y1;

        // Calcul de la norme de |vect(AB)|
        double normev1 = sqrt(pow(vx1, 2) + pow(vy1, 2));
        // Calcul de la norme de |vect(AD)|
        double normev2 = sqrt(pow(vx2, 2) + pow(vy2, 2));

        return normev1 * normev2;
    }

    virtual void accept(VisitorForm * vf);
};

#endif //CLIENTCPP_RECT_HPP
