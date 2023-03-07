//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_SAVEFILECOR_HPP
#define CLIENTCPP_SAVEFILECOR_HPP

#pragma once
#include <iostream>
#include <string>
#include "../../../Error.hpp"

using namespace std;

class SaveFileCOR {
protected:
    SaveFileCOR * m_next = nullptr;
public:
    ~SaveFileCOR() {
        delete m_next;
    }

    void solve(const string& input) const {
        if (isFormat(input)) {
            solveSave(input);
        } else {
            if (m_next == nullptr) throw Error("SaveFileCOR : can't save this type of file.");
            m_next->solve(input);
        }
    }

    virtual bool isFormat(string input) const = 0;
    virtual void solveSave(string input) const = 0;
};


#endif //CLIENTCPP_SAVEFILECOR_HPP
