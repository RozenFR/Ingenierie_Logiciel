//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_RECT_HPP
#define CLIENTCPP_RECT_HPP

#include <ctgmath>

#pragma once
#include "Form.hpp"

/**
 * Class representing a Rectangle
 */
class Rect : public Form {
protected:
    double m_x1, m_y1; // Coordinate of P1
    double m_x2, m_y2; // Coordinate of P2
    double m_x3, m_y3; // Coordinate of P3
    double m_x4, m_y4; // Coordinate of P4
public:
    /**
     * Constructor of Rect
     * @param x1 x of P1
     * @param y1 y of P1
     * @param x2 x of P2
     * @param y2 y of P2
     * @param x3 x of P3
     * @param y3 y of P3
     * @param x4 x of P4
     * @param y4 y of P4
     */
    Rect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : m_x1(x1), m_x2(x2), m_x3(x3), m_x4(x4), m_y1(y1), m_y2(y2), m_y3(y3), m_y4(y4) {
    }

    /**
     * set x of P1
     * @param x coordinate x
     */
    void setX1(double x) {
        m_x1 = x;
    }

    /**
     * set y of P1
     * @param y coordinate y
     */
    void setY1(double y) {
        m_y1 = y;
    }

    /**
     * set x of P2
     * @param x coordinate x
     */
    void setX2(double x) {
        m_x2 = x;
    }

    /**
     * set y of P2
     * @param y coordinate y
     */
    void setY2(double y) {
        m_y2 = y;
    }

    /**
     * set x of P3
     * @param x coordinate x
     */
    void setX3(double x) {
        m_x3 = x;
    }

    /**
     * set y of P3
     * @param y coordinate y
     */
    void setY3(double y) {
        m_y3 = y;
    }

    /**
     * set x of P4
     * @param x coordinate x
     */
    void setX4(double x) {
        m_x4 = x;
    }

    /**
     * set y of P4
     * @param y coordinate y
     */
    void setY4(double y) {
        m_y4 = y;
    }

    /**
     * Get x of P1
     * @return x of P1
     */
    double getX1() const {
        return m_x1;
    }

    /**
     * Get y of P1
     * @return y of P1
     */
    double getY1() const {
        return m_y1;
    }

    /**
     * Get x of P2
     * @return x of P2
     */
    double getX2() const {
        return m_x2;
    }

    /**
     * Get y of P2
     * @return y of P2
     */
    double getY2() const {
        return m_y2;
    }

    /**
     * Get x of P3
     * @return x of P3
     */
    double getX3() const {
        return m_x3;
    }

    /**
     * Get y of P3
     * @return y of P3
     */
    double getY3() const {
        return m_y3;
    }

    /**
     * Get x of P4
     * @return x of P4
     */
    double getX4() const {
        return m_x4;
    }

    /**
     * Get y of P4
     * @return y of P4
     */
    double getY4() const {
        return m_y4;
    }

    /**
     * Overload string operator
     * @return ostream
     */
    virtual operator string() const {
        ostringstream oss;
        oss << "rectangle;";
        oss << "(" << m_x1 << ", " << m_y1 << ");";
        oss << "(" << m_x2 << ", " << m_y2 << ");";
        oss << "(" << m_x3 << ", " << m_y3 << ");";
        oss << "(" << m_x4 << ", " << m_y4 << ")";
        return oss.str();
    }

    /**
     * Overload == operator
     * @param rect this rectangle
     * @param other other rectangle
     * @return boolean if every value is the same
     */
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

    /**
     * Method to calculate area of Rextangle
     * @return area of this
     */
    virtual double aire() const {
        double vx1 = m_x2 - m_x1; double vy1 = m_y2 - m_y1;
        double vx2 = m_x3 - m_x1; double vy2 = m_y3 - m_y1;

        // Calcul de la norme de |vect(AB)|
        double normev1 = sqrt(pow(vx1, 2) + pow(vy1, 2));
        // Calcul de la norme de |vect(AD)|
        double normev2 = sqrt(pow(vx2, 2) + pow(vy2, 2));

        return normev1 * normev2;
    }

    /**
     * Method to copy a rectangle
     * @return copy of this
     */
    Form * copy() const {
        return new Rect(m_x1, m_y1, m_x2, m_y2, m_x3, m_y3, m_x4, m_y4);
    }

    /**
     * Method for every functionalities use with VisitorForm
     * @param vf
     */
    virtual void accept(VisitorForm * vf);
};

#endif //CLIENTCPP_RECT_HPP
