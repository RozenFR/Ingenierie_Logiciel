//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_RECTANGLE_HPP
#define CLIENTCPP_RECTANGLE_HPP

#pragma once
#include <ctgmath>
#include "Form.hpp"

class Rectangle : public Form {
protected:
    double m_x1, m_y1;
    double m_x2, m_y2;
    double m_x3, m_y3;
    double m_x4, m_y4;
public:
    Rectangle() {

    }

    Rectangle(double x1, double y1, double x2, double y2,
              double x3, double y3, double x4, double y4) : m_x1(x1), m_x2(x2), m_x3(x3), m_x4(x4), m_y1(y1), m_y2(y2), m_y3(y3), m_y4(y4) {
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

    virtual operator string() const {
        ostringstream oss;
        oss << "(" << m_x1 << ", " << m_y2 << ");";
        oss << "(" << m_x2 << ", " << m_y2 << ");";
        oss << "(" << m_x3 << ", " << m_y3 << ");";
        oss << "(" << m_x4 << ", " << m_y4 << ")";
        return oss.str();
    }

    virtual void accept(const VisitorForme * vf) const;

};

#endif //CLIENTCPP_RECTANGLE_HPP
