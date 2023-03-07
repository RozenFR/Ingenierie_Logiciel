//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_READRECTANGLECOR_HPP
#define CLIENTCPP_READRECTANGLECOR_HPP


#include <regex>
#include "ReadFormCOR.hpp"
#include "../Rect.hpp"

class ReadRectangleCOR : public ReadFormCOR {
    bool isForm(string input) const override {
        return input.find("rectangle") != string::npos;
    }

    Form * solveForm(string input) const override {
        Rect * rect = new Rect(0, 0, 0, 0,
                                 0, 0, 0, 0);

        vector<double> list;
        smatch match;
        regex rgx(R"([\+\-]{0,1}[0-9]*[.]{0,1}[0-9]+)");

        while (regex_search(input, match, rgx)) {
            list.push_back(stod(match.str(0)));
            input = match.suffix().str();
        }

        rect->setX1(list[0]); rect->setY1(list[1]);
        rect->setX2(list[2]); rect->setY2(list[3]);
        rect->setX3(list[4]); rect->setY3(list[5]);
        rect->setX4(list[6]); rect->setY4(list[7]);

        return rect;
    }
};


#endif //CLIENTCPP_READRECTANGLECOR_HPP
