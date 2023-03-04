//
// Created by iamze on 01/03/2023.
//

#ifndef CLIENTCPP_FORMSERVICEMODIFYCOR_HPP
#define CLIENTCPP_FORMSERVICEMODIFYCOR_HPP

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
#include "../FormServiceException.hpp"
#include "../../Form.hpp"
#include "../../visitor/CoordinatesConverter.hpp"

using namespace std;

class FormServiceModifyCOR {
protected:
    FormServiceModifyCOR * m_next;

public:
    FormServiceModifyCOR * setNext(FormServiceModifyCOR * formService) {
        m_next = formService;
        return m_next;
    }

    FormServiceModifyCOR * getNext() const {
        return m_next;
    }

    ~FormServiceModifyCOR() {
        delete m_next;
    }

    void solve(int input, int index) {
        if (isFunction(input)) {
            solveFunction(index);
        } else {
            if (m_next == NULL) throw FormServiceException("Not in range of selection.");
            m_next->solve(input, index);
        }
    }
    virtual operator string() const {
        ostringstream oss;
        oss << "[FormServiceCOR]";
        return oss.str();
    }

    virtual void solveFunction(int index) const = 0;
    virtual bool isFunction(int input) = 0;
};

inline ostream& operator<<(ostream &os, const FormServiceModifyCOR &f) {
    return os << (string) f << " - " << (string) *f.getNext();
};


#endif //CLIENTCPP_FORMSERVICEMODIFYCOR_HPP
