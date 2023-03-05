//
// Created by iamze on 01/03/2023.
//

#ifndef CLIENTCPP_FORMSERVICEMODIFYDILATION_HPP
#define CLIENTCPP_FORMSERVICEMODIFYDILATION_HPP

#pragma once
#include "FormServiceModifyCOR.hpp"
#include "../../visitor/Dilation.hpp"
#include "../../../coordinates/CoordinatesSystemWorld.hpp"
#include "../../../coordinates/CoordinatesSystemScreen.hpp"

/**
 * Class managing dilation
 */
class FormServiceModifyDilation : public FormServiceModifyCOR {
public:
    /**
     * User dilation of form
     */
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

    /**
     * Method that verify choice is dilation
     * @param input user choice
     * @return if choice is correct
     */
    virtual bool isFunction(int input) {
        return input == 1;
    }

    /**
    * Overload string operator
    * @return string
    */
    virtual operator string() const {
        ostringstream oss;
        oss << "[FormServiceModifyDilation]";
        return oss.str();
    }
};


#endif //CLIENTCPP_FORMSERVICEMODIFYDILATION_HPP
