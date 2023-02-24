//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_FORMSERVICE_HPP
#define CLIENTCPP_FORMSERVICE_HPP

#pragma once
#include "FormServiceCOR.hpp"
#include "RectangleServiceCOR.hpp"
#include "CircleServiceCOR.hpp"

using namespace std;

class FormService {
protected:

    Form * processInput(string input) {
        FormServiceCOR * fs;
        fs = new class RectangleServiceCOR(new class CircleServiceCOR());
        Form * form = fs->solve(input);
        return form;
    }

public:
    FormService() {

    }

    Form * getForm(string input) {
        return processInput(input);
    }
};


#endif //CLIENTCPP_FORMSERVICE_HPP
