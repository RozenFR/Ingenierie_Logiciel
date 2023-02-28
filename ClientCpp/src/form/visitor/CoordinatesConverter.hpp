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
    const int m_px1prime = 800;
    const int m_py1prime = 0;
    const int m_px2prime = 0;
    const int m_py2prime = 500;

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

    double abs(double x) {
        return (x < 0) ? -x : x;
    }

    double min(double x, double y) {
        return (x < y) ? x : y;
    }

    string sign(double x) {
        return (x < 0) ? "-" : "+";
    }

    void setP1(double x, double y) {
        m_px1 = x;
        m_py1 = y;
    }

    void setP2(double x, double y) {
        m_px2 = x;
        m_py2 = y;
    }

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

    void setEta1() {
        m_eta1 = (sign(m_px2 - m_px2) == sign(m_px2prime - m_px1prime)) ? 1 : -1;
    }

    void setEta2() {
        m_eta2 = (sign(m_py2 - m_py2) == sign(m_py2prime - m_py1prime)) ? 1 : -1;
    }

    void setA() {
        double cx = (m_px1 + m_px2) / 2;
        double cxprime = (m_px1prime + m_px2prime) / 2;
        m_a = cxprime - (m_lambda * m_eta1 * cx);
    }

    void setB() {
        double cy = (m_py1 + m_py2) / 2;
        double cyprime = (m_py1prime + m_py2prime) / 2;
        m_b = cyprime - (m_lambda * m_eta2 * cy);
    }

    double transferX(double x) const {
        return m_lambda * m_eta1 * x + m_a;
    }

    double transferY(double y) const {
        return m_lambda * m_eta2 * y + m_b;
    }

public:
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

    virtual void visite(Cross * croix) {

    }

    virtual void visite(Circle * circle) {
        // Virtualize Point of circle
        double x = circle->getX() + circle->getRadius();
        double y = circle->getY();
        x = transferX(x);
        y = transferY(y);

        // Transfer center
        circle->setX(transferX(circle->getX()));
        circle->setY(transferY(circle->getY()));

        // Calculate new radius
        circle->setRadius(sqrt(pow(x - circle->getX(), 2)
                               + pow(y - circle->getY(), 2)));
    }

    virtual void visite(Rect * rect) {
        // Modify X axis
        rect->setX1(transferX(rect->getX1()));
        rect->setX2(transferX(rect->getX2()));
        rect->setX3(transferX(rect->getX3()));
        rect->setX4(transferX(rect->getX4()));

        // Modify Y axis
        rect->setY1(transferY(rect->getY1()));
        rect->setY2(transferY(rect->getY2()));
        rect->setY3(transferY(rect->getY3()));
        rect->setY4(transferY(rect->getY4()));
    }

};


#endif //CLIENTCPP_COORDINATESCONVERTER_HPP
