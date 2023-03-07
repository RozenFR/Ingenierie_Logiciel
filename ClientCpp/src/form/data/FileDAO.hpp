//
// Created by iamze on 03/03/2023.
//

#ifndef CLIENTCPP_FILEDAO_HPP
#define CLIENTCPP_FILEDAO_HPP

#include <iostream>
#include <vector>
#include "../Form.hpp"

using namespace std;

class FileDAO {
public:
    virtual void read(string filename) const = 0;

    virtual void write(string filename) const = 0;
};


#endif //CLIENTCPP_FILEDAO_HPP
