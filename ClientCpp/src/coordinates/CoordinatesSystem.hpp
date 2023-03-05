//
// Created by iamze on 04/03/2023.
//

#ifndef CLIENTCPP_COORDINATESSYSTEM_HPP
#define CLIENTCPP_COORDINATESSYSTEM_HPP


#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include "../form/Form.hpp"

using namespace std;

/**
 * Parent class that manage every kind of coordinates system\n
 * In occurence :\n
 * - World -> Singleton\n
 * - Screen -> Singleton\n
 * If we want to generalize more, we can create a children wich is not a singleton
 * but in our case, it is useless so we just create these 2 Singleton
 */
class CoordinatesSystem {
protected:
    // Vector of Form
    vector<Form *> v_form;

    /**
     * Delete every form when CoordinatesSystem is detroyed
     */
    ~CoordinatesSystem() {
        for (int i = 0; i < v_form.size(); i++) {
            delete v_form[i];
        }
    }

public:
    /**
     *  Virtual function to add a form
     * @param form Pointer of form to add
     */
    virtual void AddForm(Form * form) = 0;

    /**
     * Virtual function to remove a form with index
     * @param i index of form
     */
    virtual void RemoveForm(int i) = 0;

    /**
     * Convert a CoordinatesSystem into a string
     * @return a string of CoordinatesSystem
     */
    virtual operator string() const = 0;

    /**
     * Method to get form's vector
     * @return vector of form
     */
    vector<Form *> getForms() {
        return v_form;
    }
};

/**
 * Overload of <<
 * @param os main input
 * @param cs CoordinatesSystem target
 * @return ostream
 */
inline ostream& operator<<(ostream &os, const CoordinatesSystem &cs) {
    return os << (string) cs;
}


#endif //CLIENTCPP_COORDINATESSYSTEM_HPP
