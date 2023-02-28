//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_FORMSERVICECREATION_HPP
#define CLIENTCPP_FORMSERVICECREATION_HPP

#pragma once
#include "FormServiceCreationCOR.hpp"
#include "RectangleServiceCreationCOR.hpp"
#include "CircleServiceCreationCOR.hpp"

using namespace std;

class FormServiceCreation {
protected:

    void processInput(int input) {
        FormServiceCreationCOR * fs;
        fs = new class RectangleServiceCOR(new CircleServiceCreationCOR());
        fs->solve(input);
    }

public:
    FormServiceCreation() {

    }

    void getForm(int input) {
        processInput(input);
    }
};


#endif //CLIENTCPP_FORMSERVICECREATION_HPP
