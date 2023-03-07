//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_READTXTFILE_HPP
#define CLIENTCPP_READTXTFILE_HPP

#pragma once
#include "ReadFileCOR.hpp"
#include "../TXTFileDAO.hpp"

class ReadTXTFile : public ReadFileCOR {
    bool isFormat(string input) const override {
        return input.find(".txt") != string::npos;
    }

    void solveLoad(string input) const override {
        TXTFileDAO tfc; tfc.read(input);
    }
};


#endif //CLIENTCPP_READTXTFILE_HPP
