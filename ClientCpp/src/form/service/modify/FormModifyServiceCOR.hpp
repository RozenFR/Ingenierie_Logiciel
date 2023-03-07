//
// Created by iamze on 01/03/2023.
//

#ifndef CLIENTCPP_FORMMODIFYSERVICECOR_HPP
#define CLIENTCPP_FORMMODIFYSERVICECOR_HPP

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
#include "../FormServiceException.hpp"
#include "../../Form.hpp"
#include "../../visitor/CoordinatesConverter.hpp"

using namespace std;

/**
 * Chain of Responsability to modify form
 */
class FormModifyServiceCOR {
protected:
    // Represent the node of chain of resposability
    FormModifyServiceCOR * m_next;
public:

    /**
     * Destroyer of FormServiceCreationCOR
     */
    ~FormModifyServiceCOR() {
        delete m_next;
    }

    /**
     * Method that set next node in chain of creation responsability
     * @param formService new node
     * @return next
     */
    FormModifyServiceCOR * setNext(FormModifyServiceCOR * formService) {
        m_next = formService;
        return m_next;
    }

    /**
     * Method that get next
     * @return
     */
    FormModifyServiceCOR * getNext() const {
        return m_next;
    }

    /**
     * Method that solve current COR
     * @param input user choice
     */
    void solve(int input, int index) {
        if (isFunction(input)) {
            solveFunction(index);
        } else {
            if (m_next == NULL) throw FormServiceException("Not in range of selection.");
            m_next->solve(input, index);
        }
    }

    /**
     * Overload string operator
     * @return string of this
     */
    virtual operator string() const {
        ostringstream oss;
        oss << "[FormServiceCOR]";
        return oss.str();
    }

    /**
     * Abstract method that solve modify of form
     */
    virtual void solveFunction(int index) const = 0;

    /**
     * Abstract method that verify if input is right
     * @param input user choice
     * @return is user is right in node
     */
    virtual bool isFunction(int input) = 0;
};

inline ostream& operator<<(ostream &os, const FormModifyServiceCOR &f) {
    return os << (string) f << " - " << (string) *f.getNext();
};


#endif //CLIENTCPP_FORMMODIFYSERVICECOR_HPP
