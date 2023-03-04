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
    virtual void create() const = 0;
    virtual vector<Form *> read() const = 0;
    virtual void update(vector<Form *> forms) const = 0;
    virtual void remove(vector<Form *> forms) const = 0;
};


#endif //CLIENTCPP_FILEDAO_HPP
