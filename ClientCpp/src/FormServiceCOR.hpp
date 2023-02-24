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

    FormServiceCOR * setNext(FormServiceCOR * formService) {
        m_next = formService;
        return m_next;
    }

    FormServiceCOR *getNext() const {
        return m_next;
    }

    Form * solve(string input) {
        if (m_next == NULL) throw FormServiceException("Not in range of selection.");

        if (isForm(input)) {
            return solveForm();
        } else {
            return m_next->solve(input);
        }
    }
    virtual operator string() const {
        ostringstream oss;
        oss << "[FormServiceCOR]";
        return oss.str();
    }

    virtual Form * solveForm() = 0;
    virtual bool isForm(string input) = 0;
};

inline ostream& operator<<(ostream &os, const FormServiceCOR &f) {
    return os << (string) f << " - " << (string) *f.getNext();
};


#endif //CLIENTCPP_FORMSERVICECOR_HPP
