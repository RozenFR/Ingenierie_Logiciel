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
    /**
     * method that process user input to activate CreationService
     * @param input user choice
     */
    void processInput(int input) {
        FormServiceCreationCOR * fs;
        fs = new RectangleServiceCreationCOR(new CircleServiceCreationCOR());
        fs->solve(input);
    }

public:
    /**
     * Constructor of FormServiceCreation
     */
    FormServiceCreation() {

    }

    /**
     * Method that manage user choice
     * @param input user choice
     */
    void getForm(int input) {
        processInput(input);
    }
};


#endif //CLIENTCPP_FORMSERVICECREATION_HPP
