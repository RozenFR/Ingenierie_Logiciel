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
        cout << "Before : " << *circle << endl;
        // We calculate the distance between point of rotation and the center
        double distance = sqrt(pow(circle->getX() - m_x, 2) + pow(circle->getY() - m_y, 2));

        // We change Coordinate System and use polar coordinates
        // So now x = R * cos(theta)
        // and y = R * sin(theta)
        // Our new center with polar coordinates
        double nc[2]; nc[0] = circle->getX() - m_x; nc[1] = circle->getY() - m_y;

        // We calculate lambda wich is the angle between the x axis and OA
        double lambda = acos(nc[0]/distance);

        // We calculate the new center with the polar coordinate
        double rc[2]; rc[0] = distance * cos(lambda + m_rad); rc[1] = distance * sin(lambda + m_rad);

        // Now we need to convert polar coordinate to carthesian coordinate
        circle->setX(round(rc[0] + m_x));
        circle->setY(round(rc[1] + m_y));

        cout << "After : " << *circle << endl;
    }

    /**
     * Method to rotate a rectangle
     * @param rect target Rectangle
     */
    virtual void visite(Rect * rect) {
        // We calculate the distance between point of rotation and the center
        double d1 = sqrt(pow(rect->getX1() - m_x, 2) + pow(rect->getY1() - m_y, 2));
        double d2 = sqrt(pow(rect->getX2() - m_x, 2) + pow(rect->getY2() - m_y, 2));
        double d3 = sqrt(pow(rect->getX3() - m_x, 2) + pow(rect->getY3() - m_y, 2));
        double d4 = sqrt(pow(rect->getX4() - m_x, 2) + pow(rect->getY4() - m_y, 2));

        // We change Coordinate System and use polar coordinates
        // So now x = R * cos(theta)
        // and y = R * sin(theta)
        // Our new center with polar coordinates
        double nc1[2]; nc1[0] = rect->getX1() - m_x; nc1[1] = rect->getY1() - m_y;
        double nc2[2]; nc2[0] = rect->getX2() - m_x; nc1[1] = rect->getY2() - m_y;
        double nc3[2]; nc3[0] = rect->getX3() - m_x; nc1[1] = rect->getY3() - m_y;
        double nc4[2]; nc4[0] = rect->getX4() - m_x; nc1[1] = rect->getY4() - m_y;

        // We calculate lambda wich is the angle between the x axis and OA
        double lambda1 = acos(nc1[0]/d1);
        double lambda2 = acos(nc2[0]/d2);
        double lambda3 = acos(nc3[0]/d3);
        double lambda4 = acos(nc4[0]/d4);

        // We calculate the new center with the polar coordinate
        double rc1[2]; rc1[0] = d1 * cos(lambda1 + m_rad); rc1[1] = d1 * sin(lambda1 + m_rad);
        double rc2[2]; rc2[0] = d2 * cos(lambda2 + m_rad); rc2[1] = d2 * sin(lambda2 + m_rad);
        double rc3[2]; rc3[0] = d3 * cos(lambda3 + m_rad); rc3[1] = d3 * sin(lambda3 + m_rad);
        double rc4[2]; rc4[0] = d4 * cos(lambda4 + m_rad); rc4[1] = d4 * sin(lambda4 + m_rad);

        // Now we need to convert polar coordinate to carthesian coordinate
        rect->setX1(rc1[0] + m_x); rect->setY1(rc1[1] + m_y);
        rect->setX2(rc2[0] + m_x); rect->setY2(rc2[1] + m_y);
        rect->setX3(rc3[0] + m_x); rect->setY3(rc3[1] + m_y);
        rect->setX4(rc4[0] + m_x); rect->setY4(rc4[1] + m_y);
    }
};


#endif //CLIENTCPP_ROTATE_HPP
