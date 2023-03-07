//
// Created by iamze on 03/03/2023.
//

#ifndef CLIENTCPP_TXTFILEDAO_HPP
#define CLIENTCPP_TXTFILEDAO_HPP


#include <fstream>
#include "FileDAO.hpp"
#include "../../coordinates/CoordinatesSystemWorld.hpp"
#include "../read/ReadForm.hpp"
#include "../../coordinates/CoordinatesSystemScreen.hpp"

#define MAX_FILE_EXTENSION 10

class TXTFileDAO : public FileDAO {
public:

    /**
     * Method to read a txt file and load forms on client
     * @param filename name of the file
     */
    void read(string filename) const override {
        vector<Form *> v_forms;

        // Open file
        fstream fs;
        fs.open(filename, ios::in);

        // Loop each line of file
        string output;
        while (!fs.eof()) {
            fs >> output;
            Form * form = ReadForm::StringToForm(output);
            if (form == nullptr) throw Error("TXTFileDAO : Format of form in the file " +
                                            filename + " is incorrect.");
            CoordinatesSystemWorld::GetInstance()->AddForm(form);
            CoordinatesSystemScreen::GetInstance()->AddForm(form);
        }
    }

    void write(string filename) const override {
        fstream fs;

        // Create file if not created
        fs.open(filename, ios::out | ios::app);

        // Verify if file is created
        if (!fs) throw Error("File has not been created : " + filename);
        else {
            cout << "Writing forms in file ..." << endl;
            for (Form * form : CoordinatesSystemWorld::GetInstance()->getForms()) {
                fs << *form << endl;
            }
        }
        fs.close();
        cout << "File has been writen !";
    }
};


#endif //CLIENTCPP_TXTFILEDAO_HPP
