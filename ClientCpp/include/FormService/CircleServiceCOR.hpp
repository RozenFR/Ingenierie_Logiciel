//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_CIRCLESERVICECOR_HPP
#define CLIENTCPP_CIRCLESERVICECOR_HPP

#pragma once
#include "FormServiceCOR.hpp"
#include "../form/Circle.hpp"
#include "FormServiceException.hpp"

class CircleServiceCOR : public FormServiceCOR {

public:
    virtual Form * solveForm() const {
        double x1, y1;
        double radius;
        bool ok;

        do {
            ok = true;
            cin >> x1;
            if (!cin) {
                ok = false;
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                string dummy;
                getline(cin, dummy);
                if (dummy.find_first_not_of(" ") != string::npos) ok = false;
            }
            if (!ok) throw FormServiceException("x1 must be double.");
        } while (!ok);

        do {
            ok = true;
            cin >> radius;
            if (!cin) {
                ok = false;
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                string dummy;
                getline(cin, dummy);
                if (dummy.find_first_not_of(" ") != string::npos) ok = false;
            }
            if (!ok) throw FormServiceException("x1 must be double.");
        } while (!ok);

        do {
            ok = true;
            cin >> radius;
            if (!cin) {
                ok = false;
                cin.clear();
                cin.ignore(1000, '\n');
            } else {
                string dummy;
                getline(cin, dummy);
                if (dummy.find_first_not_of(" ") != string::npos) ok = false;
            }
            if (!ok) throw FormServiceException("x1 must be double.");
        } while (!ok);

        Circle * rond = new Circle(x1, y1, radius);
        return rond;
    }

    bool isForm(const string input) const {
        return input == "Circle";
    }
};


#endif //CLIENTCPP_CIRCLESERVICECOR_HPP
