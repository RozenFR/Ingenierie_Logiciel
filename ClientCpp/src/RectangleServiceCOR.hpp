//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_RECTANGLESERVICECOR_HPP
#define CLIENTCPP_RECTANGLESERVICECOR_HPP

#pragma once
#include "FormServiceCOR.hpp"
#include "FormServiceException.hpp"
#include "Rect.hpp"
#include "CircleServiceCOR.hpp"

class RectangleServiceCOR : public FormServiceCOR {
public:

    RectangleServiceCOR() {

    }

    RectangleServiceCOR(FormServiceCOR * fs) {
        setNext(fs);
    }

    virtual Form * solveForm() {
        double x1, y1;
        double x2, y2;
        double x3, y3;
        double x4, y4;

        cout << "x1 = " << endl;
        cin >> x1;
        cout << endl;
        cout << "y1 = " << endl;
        cin >> y1;
        cout << endl;

        cout << "x2 = " << endl;
        cin >> x2;
        cout << endl;
        cout << "y2 = " << endl;
        cin >> y2;
        cout << endl;

        cout << "x3 = " << endl;
        cin >> x3;
        cout << endl;
        cout << "y3 = " << endl;
        cin >> y3;
        cout << endl;

        cout << "x4 = " << endl;
        cin >> x4;
        cout << endl;
        cout << "y4 = " << endl;
        cin >> y4;
        cout << endl;

        Form * rect = new Rect(x1, y1, x2, y2, x3, y3, x4, y4);
        return rect;
    }

    virtual bool isForm(string input) {
        return input == "1";
    }

    virtual operator string() const {
        ostringstream oss;
        oss << "RectangleServiceCOR";
        return oss.str();
    }
};


#endif //CLIENTCPP_RECTANGLESERVICECOR_HPP
