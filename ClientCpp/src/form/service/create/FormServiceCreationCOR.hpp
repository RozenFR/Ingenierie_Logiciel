//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_FORMSERVICECREATIONCOR_HPP
#define CLIENTCPP_FORMSERVICECREATIONCOR_HPP

#include "../FormServiceException.hpp"

using namespace std;

class Form;

class FormServiceCreationCOR {
protected:
    FormServiceCreationCOR * m_next;
public:

    FormServiceCreationCOR * setNext(FormServiceCreationCOR * formService) {
        m_next = formService;
        return m_next;
    }

    FormServiceCreationCOR *getNext() const {
        return m_next;
    }

    ~FormServiceCreationCOR() {
        delete m_next;
    }

    void solve(int input) {
        if (m_next == NULL) throw FormServiceException("Not in range of selection.");

        if (isForm(input)) {
            solveForm();
        } else {
            m_next->solve(input);
        }
    }
    virtual operator string() const {
        ostringstream oss;
        oss << "[FormServiceCOR]";
        return oss.str();
    }

    virtual void solveForm() const = 0;
    virtual bool isForm(int input) = 0;
};

inline ostream& operator<<(ostream &os, const FormServiceCreationCOR &f) {
    return os << (string) f << " - " << (string) *f.getNext();
};


#endif //CLIENTCPP_FORMSERVICECREATIONCOR_HPP
