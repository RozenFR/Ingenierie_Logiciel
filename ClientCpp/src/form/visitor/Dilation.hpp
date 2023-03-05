//
// Created by iamze on 28/02/2023.
//

#ifndef CLIENTCPP_DILATION_HPP
#define CLIENTCPP_DILATION_HPP

#pragma once
#include "VisitorForm.hpp"

/**
 * Class that manage Dilation of a form
 */
class Dilation : public VisitorForm {
protected:
    double m_x; // x of dilation
    double m_y; // y of dilation
    double m_coef; // coefficient of dilation
public:
    /**
     * Constructor of Dilation
     * @param x x of dilation
     * @param y y of dilation
     * @param coef coefficient of dilation
     */
    Dilation(double x, double y, double coef) {
        m_x = x;
        m_y = y;
        m_coef = coef;
    }

    /**
     * @NotImplemented
     * @param croix
     */
    virtual void visite(Cross * croix) {

    }

    /**
     * Method that dilate a circle from point of dilation with a coefficient of dilation
     * @param circle target circle
     */
    virtual void visite(Circle * circle) {
        double * v1 = new double[2];
        double rx;
        // Setup Vector
        v1[0] = circle->getX() - m_x;
        v1[1] = circle->getY() - m_y;
        rx = circle->getX() + circle->getRadius() - m_x;

        // Setup new Vector with coef
        v1[0] *= m_coef;
        v1[1] *= m_coef;
        rx *= m_coef;

        // Define new coordinate of center
        circle->setX(m_x + v1[0]);
        circle->setY(m_y + v1[1]);

        // Define new radius
        double nr = sqrt(pow(v1[0] - rx, 2));
        circle->setRadius(nr);

    }

    /**
     * Method that dilate a rectangle from point of dilation with a coefficient of dilation
     * @param rect target rectangle
     */
    virtual void visite(Rect * rect){
        double *v1 = new double[2], *v2 = new double[2], *v3 = new double[2], *v4 = new double[2];

        // Setup vector
        v1[0] = rect->getX1() - m_x; v1[1] = rect->getY1() - m_y;
        v2[0] = rect->getX2() - m_x; v2[1] = rect->getY2() - m_y;
        v3[0] = rect->getX3() - m_x; v3[1] = rect->getY3() - m_y;
        v4[0] = rect->getX4() - m_x; v4[1] = rect->getY4() - m_y;

        // Setup new vector with coef
        v1[0] *= m_coef; v1[1] *= m_coef;
        v2[0] *= m_coef; v2[1] *= m_coef;
        v3[0] *= m_coef; v3[1] *= m_coef;
        v4[0] *= m_coef; v4[1] *= m_coef;

        // Define new coordinate of form
        rect->setX1(v1[0] + m_x); rect->setY1(v1[1] + m_y);
        rect->setX2(v2[0] + m_x); rect->setY2(v2[1] + m_y);
        rect->setX3(v3[0] + m_x); rect->setY3(v3[1] + m_y);
        rect->setX4(v4[0] + m_x); rect->setY4(v4[1] + m_y);
    }
};


#endif //CLIENTCPP_DILATION_HPP
