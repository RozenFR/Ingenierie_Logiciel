//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_READFILE_HPP
#define CLIENTCPP_READFILE_HPP

#pragma once
#include <iostream>
#include <string>
#include "ReadFileCOR.hpp"
#include "ReadTXTFile.hpp"

using namespace std;

class ReadFile {
public:
    static void readfile(string input) {
        ReadFileCOR * sfc = new ReadTXTFile();
        sfc->solve(input);
    }
};


#endif //CLIENTCPP_READFILE_HPP
