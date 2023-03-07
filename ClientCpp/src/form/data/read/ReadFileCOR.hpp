//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_READFILECOR_HPP
#define CLIENTCPP_READFILECOR_HPP

#pragma once
#include <iostream>
#include <string>
#include "../../../Error.hpp"

using namespace std;

class ReadFileCOR {
protected:
    ReadFileCOR * m_next = nullptr;
public:
    ~ReadFileCOR() {
        delete m_next;
    }

    void solve(const string& input) const {
        if (isFormat(input)) {
            solveLoad(input);
        } else {
            if (m_next == nullptr) throw Error("SaveFileCOR : can't save this type of file.");
            m_next->solve(input);
        }
    }

    virtual bool isFormat(string input) const = 0;
    virtual void solveLoad(string input) const = 0;

};


#endif //CLIENTCPP_READFILECOR_HPP
