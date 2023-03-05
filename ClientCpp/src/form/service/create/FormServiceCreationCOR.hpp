//
// Created by iamze on 23/02/2023.
//

#ifndef CLIENTCPP_FORMSERVICECREATIONCOR_HPP
#define CLIENTCPP_FORMSERVICECREATIONCOR_HPP

#include "../FormServiceException.hpp"

using namespace std;

/**
 * Chain of Responsability to create form
 */
class FormServiceCreationCOR {
protected:
    // Represent the node of chain of resposability
    FormServiceCreationCOR * m_next;
public:

    /**
     * Method that set next node in chain of creation responsability
     * @param formService new node
     * @return next
     */
    FormServiceCreationCOR * setNext(FormServiceCreationCOR * formService) {
        m_next = formService;
        return m_next;
    }

    /**
     * Method that get next
     * @return
     */
    FormServiceCreationCOR * getNext() const {
        return m_next;
    }

    /**
     * Destroyer of FormServiceCreationCOR
     */
    ~FormServiceCreationCOR() {
        delete m_next;
    }

    /**
     * Method that solve current COR
     * @param input user choice
     */
    void solve(int input) {
        if (isForm(input)) {
            solveForm();
        } else {
            if (m_next == NULL) throw FormServiceException("Not in range of selection.");
            m_next->solve(input);
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
     * Abstract method that solve creation of form
     */
    virtual void solveForm() const = 0;

    /**
     * Abstract method that verify if input is right
     * @param input user choice
     * @return is user is right in node
     */
    virtual bool isForm(int input) = 0;
};

inline ostream& operator<<(ostream &os, const FormServiceCreationCOR &f) {
    return os << (string) f << " - " << (string) *f.getNext();
};


#endif //CLIENTCPP_FORMSERVICECREATIONCOR_HPP
