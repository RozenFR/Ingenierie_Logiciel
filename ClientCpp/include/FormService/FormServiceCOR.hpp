//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_FORMSERVICECOR_HPP
#define CLIENTCPP_FORMSERVICECOR_HPP

#include "FormServiceException.hpp"

using namespace std;

class Form;

class FormServiceCOR {
protected:
    FormServiceCOR * m_next;
public:
    FormServiceCOR() : m_next(nullptr) {
    }

    FormServiceCOR(FormServiceCOR * fs) : m_next(fs) {

    }

    FormServiceCOR * setNext(FormServiceCOR * formService) {
        m_next = formService;
        return m_next;
    }

    Form * solve(string input) const {

        if (m_next == nullptr) throw FormServiceException("Not in range of selection.");
        if (input == "") throw FormServiceException("Input is empty.");

        if (isForm(input)) {
            return solveForm();
        } else {
            return m_next->solve(input);
        }

    }

    virtual Form * solveForm() const = 0;
    virtual bool isForm(const string input) const = 0;
};


#endif //CLIENTCPP_FORMSERVICECOR_HPP
