//
// Created by iamze on 01/03/2023.
//

#ifndef CLIENTCPP_FORMMODIFYSERVICE_HPP
#define CLIENTCPP_FORMMODIFYSERVICE_HPP

#pragma once
#include <iostream>
#include "../../Form.hpp"
#include "FormModifyServiceCOR.hpp"
#include "FormDilationModifyServiceCOR.hpp"
#include "FormRotateModifyServiceCOR.hpp"

using namespace std;

class FormModifyService {
public:
    /**
     * Method that update a form
     * @param choice user choice
     * @param index index of form to modify
     */
    void updateForm(int choice, int index) {
        FormModifyServiceCOR *f1 = new FormDilationModifyServiceCOR();
        f1->setNext(new FormRotateModifyServiceCOR());
        f1->solve(choice, index);
    }
};


#endif //CLIENTCPP_FORMMODIFYSERVICE_HPP
