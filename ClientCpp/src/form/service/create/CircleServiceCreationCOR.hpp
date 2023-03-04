//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_CIRCLESERVICECREATIONCOR_HPP
#define CLIENTCPP_CIRCLESERVICECREATIONCOR_HPP

#pragma once
#include "FormServiceCreationCOR.hpp"
#include "../FormServiceException.hpp"
#include "../../Circle.hpp"
#include "../../../CoordinatesSystemScreen.hpp"
#include "../../../CoordinatesSystemWorld.hpp"

class CircleServiceCreationCOR : public FormServiceCreationCOR {

public:
    CircleServiceCreationCOR() {

    }

    CircleServiceCreationCOR(FormServiceCreationCOR * fs) {
        setNext(fs);
    }

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

    virtual bool isForm(int input) {
        return input == 2;
    }

    virtual operator string() const {
        ostringstream oss;
        oss << "CircleServiceCOR";
        return oss.str();
    }
};


#endif //CLIENTCPP_CIRCLESERVICECREATIONCOR_HPP
