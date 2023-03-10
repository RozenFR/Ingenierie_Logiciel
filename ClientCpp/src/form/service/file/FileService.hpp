//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_FILESERVICE_HPP
#define CLIENTCPP_FILESERVICE_HPP

#pragma once
#include <iostream>
#include <string>
#include "FileServiceCOR.hpp"
#include "FileSaveServiceCOR.hpp"
#include "FileLoadServiceCOR.hpp"

using namespace std;

class FileService {
public:
    static void processFile(int input) {
        FileServiceCOR * fsc = new FileSaveServiceCOR();
        fsc->setNext(new FileLoadServiceCOR());
        fsc->solve(input);
    }
};


#endif //CLIENTCPP_FILESERVICE_HPP
