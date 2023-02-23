//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_RECTANGLESERVICECOR_HPP
#define CLIENTCPP_RECTANGLESERVICECOR_HPP

#pragma once
#include "FormServiceCOR.hpp"
#include "FormServiceException.hpp"
#include "../form/Rectangle.hpp"

class RectangleServiceCOR : public FormServiceCOR {

public:
    virtual Form * solveForm() const {
        double x1, y1;
        double x2, y2;
        double x3, y3;
        double x4, y4;
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
            cin >> y1;
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
            cin >> x2;
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
            cin >> y2;
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
            cin >> x3;
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
            cin >> y3;
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
            cin >> x4;
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
            cin >> y4;
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

        Rectangle * rectangle = new Rectangle(x1, y1, x2, y2, x3, y3, x4, y4);
        return rectangle;
    }

    bool isForm(const string input) const {
        return input == "Rectangle";
    }
};


#endif //CLIENTCPP_RECTANGLESERVICECOR_HPP
