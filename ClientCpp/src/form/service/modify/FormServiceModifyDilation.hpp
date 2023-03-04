//
// Created by iamze on 01/03/2023.
//

#ifndef CLIENTCPP_FORMSERVICEMODIFYDILATION_HPP
#define CLIENTCPP_FORMSERVICEMODIFYDILATION_HPP

#pragma once
#include "FormServiceModifyCOR.hpp"
#include "../../visitor/Dilation.hpp"
#include "../../../CoordinatesSystemWorld.hpp"
#include "../../../CoordinatesSystemScreen.hpp"

class FormServiceModifyDilation : public FormServiceModifyCOR {
public:
    virtual void solveFunction(int index) const {
        double x, y;
        double dilate;

        // User Service Input for Dilation
        // Set Point of Dilation
        cout << "xd = " << endl;
        cin >> x;
        cout << endl;
        cout << "yd = " << endl;
        cin >> y;
        cout << endl;

        // Set Dilation Coefficient
        cout << "Coefficient of Dilation = " << endl;
        cin >> dilate;

        Dilation * dilation = new Dilation(x, y, dilate);
        Form * form1 = CoordinatesSystemWorld::GetInstance()->getForms()[index];

        form1->accept(dilation);
        Form * form2 = form1->copy(); // Copy form 1 (Processed by Rotate)

        CoordinatesSystemWorld::GetInstance()->RemoveForm(index);
        CoordinatesSystemWorld::GetInstance()->AddForm(form1);
        CoordinatesSystemScreen::GetInstance()->RemoveForm(index);
        CoordinatesSystemScreen::GetInstance()->AddForm(form2);

    }
    virtual bool isFunction(int input) {
        return input == 1;
    }

    virtual operator string() const {
        ostringstream oss;
        oss << "[FormServiceModifyDilation]";
        return oss.str();
    }
};


#endif //CLIENTCPP_FORMSERVICEMODIFYDILATION_HPP
