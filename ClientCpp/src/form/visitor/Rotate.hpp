//
// Created by iamze on 28/02/2023.
//

#ifndef CLIENTCPP_ROTATE_HPP
#define CLIENTCPP_ROTATE_HPP

#pragma once
#include "VisitorForm.hpp"
#include <ctgmath>

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
        m_rad = (2 * PI / 360) * deg;
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
        double cx = circle->getX() - m_x; double cy = circle->getY() - m_y;

        // We calculate the distance between point of rotation and the center
        double r = sqrt(pow(cx, 2) + pow(cy, 2));

        // We change Coordinate System and use polar coordinates
        // So now x = R * cos(theta)
        // and y = R * sin(theta)
        // We calculate Theta
        double t = atan2(cy, cx);

        // We calculate the new center with the polar coordinate
        double rc[2];
        rc[0] = r * cos(t + m_rad);
        rc[1] = r * sin(t + m_rad);

        // Now we need to convert polar coordinate to carthesian coordinate
        circle->setX(rc[0] + m_x);
        circle->setY(rc[1] + m_y);
    }

    /**
     * Method to rotate a rectangle
     * @param rect target Rectangle
     */
    virtual void visite(Rect * rect) {
        double cx1 = rect->getX1() - m_x; double cy1 = rect->getY1() - m_y;
        double cx2 = rect->getX2() - m_x; double cy2 = rect->getY2() - m_y;
        double cx3 = rect->getX3() - m_x; double cy3 = rect->getY3() - m_y;
        double cx4 = rect->getX4() - m_x; double cy4 = rect->getY4() - m_y;

        // We calculate the distance between point of rotation and the center
        double r1 = sqrt(pow(cx1, 2) + pow(cy1, 2));
        double r2 = sqrt(pow(cx2, 2) + pow(cy2, 2));
        double r3 = sqrt(pow(cx3, 2) + pow(cy3, 2));
        double r4 = sqrt(pow(cx4, 2) + pow(cy4, 2));

        // We change Coordinate System and use polar coordinates
        // So now x = R * cos(theta)
        // and y = R * sin(theta)
        // We calculate Theta
        double t1 = atan2(cy1, cx1);
        double t2 = atan2(cy2, cx2);
        double t3 = atan2(cy3, cx3);
        double t4 = atan2(cy4, cx4);

        // We calculate the new center with the polar coordinate
        double rc1[2], rc2[2], rc3[2], rc4[2];
        rc1[0] = r1 * cos(t1 + m_rad); rc1[1] = r1 * sin(t1 + m_rad);
        rc2[0] = r2 * cos(t2 + m_rad); rc2[1] = r2 * sin(t2 + m_rad);
        rc3[0] = r3 * cos(t3 + m_rad); rc3[1] = r3 * sin(t3 + m_rad);
        rc4[0] = r4 * cos(t4 + m_rad); rc4[1] = r4 * sin(t4 + m_rad);

        // Now we need to convert polar coordinate to carthesian coordinate
        rect->setX1(rc1[0] + m_x); rect->setY1(rc1[1] + m_y);
        rect->setX2(rc2[0] + m_x); rect->setY2(rc2[1] + m_y);
        rect->setX3(rc3[0] + m_x); rect->setY3(rc3[1] + m_y);
        rect->setX4(rc4[0] + m_x); rect->setY4(rc4[1] + m_y);
    }
};


#endif //CLIENTCPP_ROTATE_HPP
