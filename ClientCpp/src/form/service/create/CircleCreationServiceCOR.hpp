//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_CIRCLECREATIONSERVICECOR_HPP
#define CLIENTCPP_CIRCLECREATIONSERVICECOR_HPP

#pragma once
#include "FormCreationServiceCOR.hpp"
#include "../FormServiceException.hpp"
#include "../../Circle.hpp"
#include "../../../coordinates/CoordinatesSystemScreen.hpp"
#include "../../../coordinates/CoordinatesSystemWorld.hpp"

/**
 * Class managing creation of circle
 */
class CircleCreationServiceCOR : public FormCreationServiceCOR {
public:
    /**
     * Constructor of CircleServiceCreationCOR
     */
    CircleCreationServiceCOR() {

    }

    /**
     * Constructor of CircleServiceCreationCOR, set next in construction
     * @param fs next node
     */
    CircleCreationServiceCOR(FormCreationServiceCOR * fs) {
        setNext(fs);
    }

    /**
     * User Creation of Circle
     */
    virtual void solveForm() const {
        double x, y;
        double radius;

        // User Service Input for Circle
        // Set Center
        cout << "x1 = " << endl;
        cin >> x;
        cout << endl;
        cout << "y1 = " << endl;
        cin >> y;
        cout << endl;

        // Set Radius
        cout << "radius = " << endl;
        cin >> radius;

        // Create 2 forms to add on each CoordinatesSystem
        Form * circleWorld = new Circle(x, y, radius);
        Form * circleScreen = new Circle(x, y, radius);

        // Add to Singleton World and Screen
        CoordinatesSystemWorld::GetInstance()->AddForm(circleWorld);
        CoordinatesSystemScreen::GetInstance()->AddForm(circleScreen); // Will do conversion in Singleton
    }

    /**
     * Method that verify choice is circle
     * @param input user choice
     * @return if choice is correct
     */
    virtual bool isForm(int input) {
        return input == 2;
    }

    /**
     * Overload string operator
     * @return string
     */
    virtual operator string() const {
        ostringstream oss;
        oss << "CircleServiceCOR";
        return oss.str();
    }
};


#endif //CLIENTCPP_CIRCLECREATIONSERVICECOR_HPP
