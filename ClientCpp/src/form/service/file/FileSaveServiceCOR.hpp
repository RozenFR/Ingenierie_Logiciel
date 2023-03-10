//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_FILESAVESERVICECOR_HPP
#define CLIENTCPP_FILESAVESERVICECOR_HPP

#pragma once
#include "FileServiceCOR.hpp"
#include "../../data/write/SaveFile.hpp"

class FileSaveServiceCOR : public FileServiceCOR {
    bool isChoice(int input) const override {
        return input == 2;
    }

    void solveFile(int input) const override {
        string filename;

        cout << "File Name (Absolute Path or Relative Path) : " << endl;
        cin >> filename;

        // Use Static Function to Save
        SaveFile::savefile(filename);
    }
};


#endif //CLIENTCPP_FILESAVESERVICECOR_HPP
