//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_COORDINATESCONVERTER_HPP
#define CLIENTCPP_COORDINATESCONVERTER_HPP

#include <tgmath.h>
#include "VisitorForm.hpp"

class CoordinatesConverter : public VisitorForm {

protected:
    // Size of screen
    const int m_px1prime = 1920;
    const int m_py1prime = 0;
    const int m_px2prime = 0;
    const int m_py2prime = 1080;

    // Size of world view
    int m_px1 = 0;
    int m_py1 = 0;
    int m_px2 = 0;
    int m_py2 = 0;

    // Parameter of conversion
    double m_lambda = 0;
    double m_eta1 = 0;
    double m_eta2 = 0;
    double m_a = 0;
    double m_b = 0;

    /**
     * Method that calculate absolute of double
     * @param x double target
     * @return absolute value of x
     */
    double abs(double x) {
        return (x < 0) ? -x : x;
    }

    /**
     * Method that determine the minimum between 2 value
     * @param x 1st value
     * @param y  2nd value
     * @return minimum between x and y
     */
    double min(double x, double y) {
        return (x < y) ? x : y;
    }

    /**
     * method that determine the sign of a double
     * @param x double target
     * @return string sign of double
     */
    string sign(double x) {
        return (x < 0) ? "-" : "+";
    }

    /**
     * Method that set P1 world view
     * @param x x coordinate of P1
     * @param y y coordinate of P1
     */
    void setP1(double x, double y) {
        m_px1 = x;
        m_py1 = y;
    }

    /**
     * Method that set P2 world view
     * @param x x coordinate of P2
     * @param y y coordinate of P2
     */
    void setP2(double x, double y) {
        m_px2 = x;
        m_py2 = y;
    }

    /**
     * Method that set Lambda
     */
    void setLambda() {
        // Calculate each delta
        double delta_xprime = abs(m_px2prime - m_px1prime);
        double delta_x = abs(m_px2 - m_px1);
        double delta_yprime = abs(m_py2prime - m_py1prime);
        double delta_y = abs(m_py2 - m_py1);
        // Calculate Member
        double m1 = delta_xprime / delta_x;
        double m2 = delta_yprime / delta_y;

        // Calculate Lambda
        m_lambda = min(m1, m2);
    }

    /**
     * Method that set Eta1
     */
    void setEta1() {
        m_eta1 = (sign(m_px2 - m_px2) == sign(m_px2prime - m_px1prime)) ? 1 : -1;
    }

    /**
     * Method that set Eta2
     */
    void setEta2() {
        m_eta2 = (sign(m_py2 - m_py2) == sign(m_py2prime - m_py1prime)) ? 1 : -1;
    }

    /**
     * Method that set a
     */
    void setA() {
        double cx = (m_px1 + m_px2) / 2;
        double cxprime = (m_px1prime + m_px2prime) / 2;
        m_a = cxprime - (m_lambda * m_eta1 * cx);
    }

    /**
     * Method that set b
     */
    void setB() {
        double cy = (m_py1 + m_py2) / 2;
        double cyprime = (m_py1prime + m_py2prime) / 2;
        m_b = cyprime - (m_lambda * m_eta2 * cy);
    }

    /**
     * Method of x's translation with convert parameter
     * @param x double to convert
     * @return converted double
     */
    double transferX(double x) const {
        return m_lambda * m_eta1 * x + m_a;
    }

    /**
     * Method of y's translation with convert parameter
     * @param y double to convert
     * @return converted double
     */
    double transferY(double y) const {
        return m_lambda * m_eta2 * y + m_b;
    }

public:
    /**
     * Constructor of CoordinatesConverter
     * @param px1 x of P1
     * @param py1 y of P1
     * @param px2 x of P2
     * @param py2 y of P2
     */
    CoordinatesConverter(const double px1, const double py1,
                         const double px2, const double py2) {
        setP1(px1, py1);
        setP2(px2, py2);
        setLambda();
        setEta1();
        setEta2();
        setA();
        setB();
    }

    /**
     * @NotImplementd
     * @param croix
     */
    virtual void visite(Cross * croix) {

    }

    /**
     * Transform a circle in World to Screen
     * @param circle circle target
     */
    virtual void visite(Circle * circle) {
        // Virtualize Point of circle
        double x = circle->getX() + circle->getRadius();
        double y = circle->getY();
        x = transferX(x);
        y = transferY(y);

        // Transfer center
        circle->setX(round(transferX(circle->getX())));
        circle->setY(round(transferY(circle->getY())));

        // Calculate new radius
        circle->setRadius(round(sqrt(pow(x - circle->getX(), 2)
                               + pow(y - circle->getY(), 2))));
    }

    /**
     * Transform a rectangle in World to Screen
     * @param rect rectangle target
     */
    virtual void visite(Rect * rect) {
        // Modify X axis
        rect->setX1(round(transferX(rect->getX1())));
        rect->setX2(round(transferX(rect->getX2())));
        rect->setX3(round(transferX(rect->getX3())));
        rect->setX4(round(transferX(rect->getX4())));

        // Modify Y axis
        rect->setY1(round(transferY(rect->getY1())));
        rect->setY2(round(transferY(rect->getY2())));
        rect->setY3(round(transferY(rect->getY3())));
        rect->setY4(round(transferY(rect->getY4())));
    }

};


#endif //CLIENTCPP_COORDINATESCONVERTER_HPP
