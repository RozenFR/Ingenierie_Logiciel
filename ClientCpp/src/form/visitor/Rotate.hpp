//
// Created by iamze on 28/02/2023.
//

#ifndef CLIENTCPP_ROTATE_HPP
#define CLIENTCPP_ROTATE_HPP

#pragma once
#include "VisitorForm.hpp"

/**
 * Class reprensenting the functionnality of Rotating a Form
 */
class Rotate : public VisitorForm{
protected:
    double m_x; // coordinate x of rotation
    double m_y; // y coordinate y of rotation
    double m_rad; // number reprensenting the rotation in radian

public:

    /**
     * Main Constructor of Rotate
     * @param x coordinate x of rotation
     * @param y coordinate y of rotation
     * @param deg number reprensenting the rotation in radian
     */
    Rotate(double x, double y, double deg) {
        m_x = x;
        m_y = y;
        m_rad = (PI / 180) * deg;
    }

    /**
     * Method to rotate a Cross
     * @param cross target Cross
     */
    virtual void visite(Cross * cross) {
        // NotImplemented
    }

    /**
     * Method to Rotate a Circle
     * @param circle target circle
     */
    virtual void visite(Circle * circle) {
        // We use complex to determine the new vector that will place the new point
        // z = x + iy
        complex<double> circomp(circle->getX(), circle->getY());

        // Now we try to calculate A, the norm of the complex vector
        double a = norm(circomp);

        // z = Aexp(i*theta)
        // our theta is the one defined by the user storaged in this subclass
        complex<double> res = a * exp(m_rad);

        // With our result, we just have to decompose our complex into a vector
        // Like that we have our vector of translation from the point of rotation
        double v[2]; v[0] = real(res); v[1] = imag(res);

        // We set our new center point on the circle with the point of rotation and add the vector of translation
        circle->setX(m_x + v[0]);
        circle->setY(m_y + v[1]);
    }

    /**
     * Method to rotate a rectangle
     * @param rect target Rectangle
     */
    virtual void visite(Rect * rect) {
        // We use complex to determine the new vector that will place the new point
        // z = x + iy
        complex<double> rc1(rect->getX1(), rect->getY1());
        complex<double> rc2(rect->getX2(), rect->getY2());
        complex<double> rc3(rect->getX3(), rect->getY3());
        complex<double> rc4(rect->getX4(), rect->getY4());

        // Now we try to calculate A, the norm of the complex vector
        double a1 = norm(rc1);
        double a2 = norm(rc2);
        double a3 = norm(rc3);
        double a4 = norm(rc4);

        // z = Aexp(i*theta)
        // our theta is the one defined by the user storaged in this subclass
        complex<double> res1 = a1 * exp(m_rad);
        complex<double> res2 = a2 * exp(m_rad);
        complex<double> res3 = a3 * exp(m_rad);
        complex<double> res4 = a4 * exp(m_rad);

        // With our result, we just have to decompose our complex into a vectors
        // Like that we have our vector of translation from the point of rotation
        double v1[2]; v1[0] = real(res1); v1[1] = imag(res1);
        double v2[2]; v2[0] = real(res2); v2[1] = imag(res2);
        double v3[2]; v3[0] = real(res3); v3[1] = imag(res3);
        double v4[2]; v4[0] = real(res4); v4[1] = imag(res4);

        // We set our new center point on the circle with the point of rotation and add the vector of translation
        rect->setX1(m_x + v1[0]); rect->setY1(m_y + v1[1]);
        rect->setX2(m_x + v2[0]); rect->setY2(m_y + v2[1]);
        rect->setX3(m_x + v3[0]); rect->setY3(m_y + v3[1]);
        rect->setX4(m_x + v4[0]); rect->setY4(m_y + v4[1]);
    }
};


#endif //CLIENTCPP_ROTATE_HPP
