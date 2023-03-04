//
// Created by iamze on 01/03/2023.
//

#ifndef CLIENTCPP_FORMSERVICEMODIFYROTATE_HPP
#define CLIENTCPP_FORMSERVICEMODIFYROTATE_HPP

#pragma once
#include "FormServiceModifyCOR.hpp"
#include "../../visitor/Rotate.hpp"
#include "../../../CoordinatesSystemWorld.hpp"
#include "../../../CoordinatesSystemScreen.hpp"

class FormServiceModifyRotate : public FormServiceModifyCOR {
public:
    virtual void solveFunction(int index) const {
        double x, y;
        double rad;

        // User Service Input for Dilation
        // Set Point of Dilation
        cout << "xr = " << endl;
        cin >> x;
        cout << endl;
        cout << "yr = " << endl;
        cin >> y;
        cout << endl;

        // Set Dilation Coefficient
        // We ask in degree because when calling functionality we convert degree to radian
        cout << "Angle in degree = " << endl;
        cin >> rad;

        Rotate * rotate = new Rotate(x, y, rad);
        Form * form1 = CoordinatesSystemWorld::GetInstance()->getForms()[index]->copy();

        form1->accept(rotate);
        Form * form2 = form1->copy(); // Copy form 1 (Processed by Rotate)

        // Remove Form from vector and add them back with right coordinates
        CoordinatesSystemWorld::GetInstance()->RemoveForm(index);
        CoordinatesSystemScreen::GetInstance()->RemoveForm(index);
        CoordinatesSystemWorld::GetInstance()->AddForm(form1);
        CoordinatesSystemScreen::GetInstance()->AddForm(form2);
    }
    virtual bool isFunction(int input) {
        return input == 2;
    }

    virtual operator string() const {
        ostringstream oss;
        oss << "[FormServiceModifyRotate]";
        return oss.str();
    }
};


#endif //CLIENTCPP_FORMSERVICEMODIFYROTATE_HPP
