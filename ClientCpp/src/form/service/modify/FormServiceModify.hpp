//
// Created by iamze on 01/03/2023.
//

#ifndef CLIENTCPP_FORMSERVICEMODIFY_HPP
#define CLIENTCPP_FORMSERVICEMODIFY_HPP

#pragma once
#include <iostream>
#include "../../Form.hpp"
#include "FormServiceModifyCOR.hpp"
#include "FormServiceModifyDilation.hpp"
#include "FormServiceModifyRotate.hpp"

using namespace std;

class FormServiceModify {
public:
    void updateForm(int choice, int index) {
        FormServiceModifyCOR *f1 = new FormServiceModifyDilation();
        f1->setNext(new FormServiceModifyRotate());
        f1->solve(choice, index);
    }
};


#endif //CLIENTCPP_FORMSERVICEMODIFY_HPP
