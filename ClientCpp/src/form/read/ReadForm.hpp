//
// Created by iamze on 07/03/2023.
//

#ifndef CLIENTCPP_READFORM_HPP
#define CLIENTCPP_READFORM_HPP

#include <iostream>
#include "../Form.hpp"
#include "ReadFormCOR.hpp"
#include "ReadCircleCOR.hpp"
#include "ReadRectangleCOR.hpp"

using namespace std;

class ReadForm {
public:
    static Form * StringToForm(const string& input) {
        ReadFormCOR * rfc = new ReadCircleCOR();
        rfc->setNext(new ReadRectangleCOR());
        return rfc->solve(input);
    }
};


#endif //CLIENTCPP_READFORM_HPP
