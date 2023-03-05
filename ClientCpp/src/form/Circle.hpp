//
// Created by iamze on 14/12/2022.
//

#ifndef CLIENTCPP_CIRCLE_HPP
#define CLIENTCPP_CIRCLE_HPP

#pragma once
#include "Form.hpp"

#define PI 3.14159265359

/**
 * Class reprensenting a Circle
 */
class Circle : public Form {
protected:
    double m_xCenter; // x coordinate of center
    double m_yCenter; // y coordinate of center
    double m_radius;
public:
    /**
     * Constructor of Circle
     * @param x x's coordinate of center
     * @param y y's coordinate of center
     * @param radius radius of circle
     */
    Circle(double x, double y, double radius) : m_xCenter(x), m_yCenter(y), m_radius(radius) {
    }

    /**
     * Method to set x of center
     * @param x coordinate x
     */
    void setX(double x) {
        m_xCenter = x;
    }

    /**
     * Method to set y of center
     * @param y coordinate y
     */
    void setY(double y) {
        m_yCenter = y;
    }

    /**
     * Method to set radius of circle
     * @param r radius of circle
     */
    void setRadius(double r) {
        m_radius = r;
    }

    /**
     * Method to get x coordinate of center
     * @return x of center
     */
    double getX() {
        return m_xCenter;
    }

    /**
     * Method to get y coordinate of center
     * @return y of center
     */
    double getY() {
        return m_yCenter;
    }

    /**
     * Method to get radius of center
     * @return radius of circle
     */
    double getRadius() {
        return m_radius;
    }

    /**
     * Overload of string operator
     * @return string of this
     */
    virtual operator string() const {
        ostringstream oss;
        oss << "circle;";
        oss << "(" << m_xCenter << "," << m_yCenter << ");" << m_radius;
        return oss.str();
    }

    /**
     * Overload == operator
     * @param circle this circle
     * @param other other circle
     * @return boolean every value is equal
     */
    friend bool operator==(Circle &circle, Circle &other) {
        return circle.m_radius == other.m_radius
            && circle.m_yCenter == other.m_yCenter
            && circle.m_xCenter == other.m_xCenter;
    }

    /**
     * Method to calculate area of a circle
     * @return area of circle
     */
    virtual double aire() const {
        return PI * m_radius * m_radius;
    }

    /**
     * Method to copy a circle
     * @return copy of circle
     */
    Form * copy() const {
        return new Circle(m_xCenter, m_yCenter, m_radius);
    }

    /**
     * Method that implements every functionalities of Circle with FormVisitor
     * @param vf Visitor representing functionalities
     */
    virtual void accept(VisitorForm * vf);
};


#endif //CLIENTCPP_CIRCLE_HPP
