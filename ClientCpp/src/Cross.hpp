//
// Created by iamze on 12/12/2022.
//

#ifndef CLIENTCPP_CROSS_HPP
#define CLIENTCPP_CROSS_HPP

#pragma once
#include "Form.hpp"

class Cross : public Form {
protected:
    double m_up;
    double m_left;
    double m_right;
    double m_down;
public:
    Cross(double up, double left, double right, double down) : m_up(up), m_left(left), m_right(right), m_down(down) {
    }

    virtual operator string() const {
        ostringstream oss;
        oss << m_up << ", " << m_left << ", " << m_right << ", " << m_down;
        return oss.str();
    }

    virtual void accept(const VisitorForme *vf) const;
};


#endif //CLIENTCPP_CROSS_HPP
