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
    FormServiceCOR * m_fs;
public:
    FormService() {
        FormServiceCOR *rect, *rond;
        // Create New Chain of the COR
        rect = new RectangleServiceCOR();
        rond = new CircleServiceCOR();

        // Set Next
        rect->setNext(rond);
        m_fs = rect;
    }

    Form * processInput(const string input) {
        return m_fs->solve(input);
    }

};


#endif //CLIENTCPP_FORMSERVICE_HPP
