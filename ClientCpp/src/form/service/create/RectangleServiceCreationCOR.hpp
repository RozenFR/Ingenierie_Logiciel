//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_RECTANGLESERVICECREATIONCOR_HPP
#define CLIENTCPP_RECTANGLESERVICECREATIONCOR_HPP

#pragma once
#include "FormServiceCreationCOR.hpp"
#include "../FormServiceException.hpp"
#include "../../Rect.hpp"
#include "CircleServiceCreationCOR.hpp"

/**
 * Class managing creation of rectangle
 */
class RectangleServiceCreationCOR : public FormServiceCreationCOR {
public:
    /**
     * Constructor of RectangleServiceCreationCOR
     */
    RectangleServiceCreationCOR() {

    }

    /**
     * Constructor of RectangleServiceCreationCOR, set next in construction
     * @param fs
     */
    RectangleServiceCreationCOR(FormServiceCreationCOR * fs) {
        setNext(fs);
    }

    /**
     * User Creation of Rectangle
     */
    virtual void solveForm() const {
        double x1, y1;
        double x2, y2;
        double x3, y3;
        double x4, y4;

        // User Service Input for Rectangle
        // Set P1
        cout << "x1 = " << endl;
        cin >> x1;
        cout << endl;
        cout << "y1 = " << endl;
        cin >> y1;
        cout << endl;

        // Set P2
        cout << "x2 = " << endl;
        cin >> x2;
        cout << endl;
        cout << "y2 = " << endl;
        cin >> y2;
        cout << endl;

        // Set P3
        cout << "x3 = " << endl;
        cin >> x3;
        cout << endl;
        cout << "y3 = " << endl;
        cin >> y3;
        cout << endl;

        // Set P4
        cout << "x4 = " << endl;
        cin >> x4;
        cout << endl;
        cout << "y4 = " << endl;
        cin >> y4;
        cout << endl;

        // Create 2 forms to add on each CoordinatesSystem
        Form * rectWorld = new Rect(x1, y1, x2, y2, x3, y3, x4, y4);
        Form * rectScreen = new Rect(x1, y1, x2, y2, x3, y3, x4, y4);

        // Add to Singleton World and Screen
        CoordinatesSystemWorld::GetInstance()->AddForm(rectWorld);
        CoordinatesSystemScreen::GetInstance()->AddForm(rectScreen); // Will do conversion in Singleton
    }

    /**
     * Method that verify choice is rectangle
     * @param input user choice
     * @return if choice is correct
     */
    virtual bool isForm(int input) {
        return input == 1;
    }

    /**
     * Overload string operator
     * @return string
     */
    virtual operator string() const {
        ostringstream oss;
        oss << "RectangleServiceCOR";
        return oss.str();
    }
};


#endif //CLIENTCPP_RECTANGLESERVICECREATIONCOR_HPP
