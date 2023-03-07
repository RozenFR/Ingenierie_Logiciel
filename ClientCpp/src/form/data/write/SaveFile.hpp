//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_SAVEFILE_HPP
#define CLIENTCPP_SAVEFILE_HPP

#pragma once
#include <iostream>
#include <string>
#include "SaveFileCOR.hpp"
#include "SaveTXTFile.hpp"

using namespace std;

class SaveFile {
public:
    static void savefile(string input) {
        SaveFileCOR * sfc = new SaveTXTFile();
        sfc->solve(input);
    }
};


#endif //CLIENTCPP_SAVEFILE_HPP
