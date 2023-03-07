//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_FILELOADSERVICECOR_HPP
#define CLIENTCPP_FILELOADSERVICECOR_HPP

#pragma once
#include "FileServiceCOR.hpp"
#include "../../data/read/ReadFile.hpp"

class FileLoadServiceCOR : public FileServiceCOR{
    bool isChoice(int input) const override {
        return input == 1;
    }

    void solveFile(int input) const override {
        string filename;

        cout << "File Name (Absolute Path or Relative Path) : " << endl;
        cin >> filename;

        // Use Static Function to Save
        ReadFile::readfile(filename);
    }
};


#endif //CLIENTCPP_FILELOADSERVICECOR_HPP
