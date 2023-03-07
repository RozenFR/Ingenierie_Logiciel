//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_FORMCREATIONSERVICE_HPP
#define CLIENTCPP_FORMCREATIONSERVICE_HPP

#pragma once
#include "FormCreationServiceCOR.hpp"
#include "RectangleCreationServiceCOR.hpp"
#include "CircleCreationServiceCOR.hpp"

using namespace std;

class FormCreationService {
protected:
    /**
     * method that process user input to activate CreationService
     * @param input user choice
     */
    void processInput(int input) {
        FormCreationServiceCOR * fs;
        fs = new RectangleCreationServiceCOR(new CircleCreationServiceCOR());
        fs->solve(input);
    }

public:
    /**
     * Constructor of FormServiceCreation
     */
    FormCreationService() {

    }

    /**
     * Method that manage user choice
     * @param input user choice
     */
    void getForm(int input) {
        processInput(input);
    }
};


#endif //CLIENTCPP_FORMCREATIONSERVICE_HPP
