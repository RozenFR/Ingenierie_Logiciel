//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_READFORMCOR_HPP
#define CLIENTCPP_READFORMCOR_HPP

#include <iostream>
#include "../../Error.hpp"
#include "../Form.hpp"

using namespace std;

class ReadFormCOR {
protected:
    ReadFormCOR * m_next;
public:
    ~ReadFormCOR() {
        delete m_next;
    }

    ReadFormCOR * setNext(ReadFormCOR * rfc) {
        if (rfc == nullptr) throw Error("ReadFormCor : next is null");
        m_next = rfc;
        return m_next;
    }

    Form * solve(const string& input) const {
        if (isForm(input)) {
            return solveForm(input);
        } else {
            if (m_next == nullptr) throw Error("ReadFormCOR : fail to read form.");
            m_next->solve(input);
        }
        return nullptr;
    }

    virtual bool isForm(string input) const = 0;
    virtual Form * solveForm(string input) const = 0;
};


#endif //CLIENTCPP_READFORMCOR_HPP
