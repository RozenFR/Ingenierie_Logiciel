//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_READCIRCLECOR_HPP
#define CLIENTCPP_READCIRCLECOR_HPP


#include <regex>
#include "ReadFormCOR.hpp"
#include "../Circle.hpp"

class ReadCircleCOR : public ReadFormCOR {
    bool isForm(string input) const override {
        return input.find("circle") != string::npos;
    }

    Form * solveForm(string input) const override {
        Circle * circle = new Circle(0, 0, 0);

        vector<double> list;
        smatch match;
        regex rgx(R"([\+\-]{0,1}[0-9]*[.]{0,1}[0-9]+)");

        while (regex_search(input, match, rgx)) {
            list.push_back(stod(match.str(0)));
            input = match.suffix().str();
        }

        circle->setX(list[0]);
        circle->setY(list[1]);
        circle->setRadius(list[2]);

        return circle;
    }
};


#endif //CLIENTCPP_READCIRCLECOR_HPP
