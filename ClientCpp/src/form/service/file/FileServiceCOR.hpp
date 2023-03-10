//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_FILESERVICECOR_HPP
#define CLIENTCPP_FILESERVICECOR_HPP

#pragma once
#include <iostream>
#include <string>
#include "../../../Error.hpp"

using namespace std;

class FileServiceCOR {
protected:
    FileServiceCOR * m_next = nullptr;
public:
    ~FileServiceCOR() {
        delete m_next;
    }

    FileServiceCOR * setNext(FileServiceCOR * fsc) {
        m_next = fsc;
        return m_next;
    }

    void solve(int input) const {
        if (isChoice(input)) solveFile(input);
        else {
            if (m_next == nullptr) throw Error("");
            m_next->solve(input);
        }
    }

    virtual bool isChoice(int input) const = 0;
    virtual void solveFile(int input) const = 0;
};


#endif //CLIENTCPP_FILESERVICECOR_HPP
