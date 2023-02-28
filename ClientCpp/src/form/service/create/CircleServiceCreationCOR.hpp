//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_CIRCLESERVICECREATIONCOR_HPP
#define CLIENTCPP_CIRCLESERVICECREATIONCOR_HPP

#pragma once
#include "FormServiceCreationCOR.hpp"
#include "../FormServiceException.hpp"
#include "../../Circle.hpp"
#include "../../../CoordinatesSystem.hpp"

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

        cout << "x1 = " << endl;
        cin >> x;
        cout << endl;
        cout << "y1 = " << endl;
        cin >> y;
        cout << endl;

        cout << "radius = " << endl;
        cin >> radius;


        Form * circle = new Circle(x, y, radius);
        // cout << *circle << endl;
        CoordinatesSystem::GetInstance()->AddForm(circle);
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
