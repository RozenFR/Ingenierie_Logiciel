//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_SAVETXTFILE_HPP
#define CLIENTCPP_SAVETXTFILE_HPP

#pragma once
#include "SaveFileCOR.hpp"
#include "../TXTFileDAO.hpp"

class SaveTXTFile : public SaveFileCOR {
public:
    bool isFormat(string input) const override {
        return input.find(".txt") != string::npos;
    }

    void solveSave(string input) const override {
        TXTFileDAO tfc;
        tfc.write(input);
    }
};


#endif //CLIENTCPP_SAVETXTFILE_HPP
