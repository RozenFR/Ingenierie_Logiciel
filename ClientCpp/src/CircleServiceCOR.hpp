//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_CIRCLESERVICECOR_HPP
#define CLIENTCPP_CIRCLESERVICECOR_HPP

#pragma once
#include "FormServiceCOR.hpp"
#include "FormServiceException.hpp"
#include "Circle.hpp"

class CircleServiceCOR : public FormServiceCOR {

public:
    CircleServiceCOR() {

    }

    CircleServiceCOR(FormServiceCOR * fs) {
        setNext(fs);
    }

    virtual Form * solveForm() {
        double x, y;
        double radius;

        cout << "x1 = " << endl;
        cin >> x;
        cout << endl;
        cout << "y1 = " << endl;
        cin >> y;
        cout << endl;

        cout << "radius = " << endl;
        cin >> radius;


        Form * circle = new Circle(x, y, radius);
        return circle;
    }

    virtual bool isForm(string input) {
        return input == "2";
    }

    virtual operator string() const {
        ostringstream oss;
        oss << "CircleServiceCOR";
        return oss.str();
    }
};


#endif //CLIENTCPP_CIRCLESERVICECOR_HPP
