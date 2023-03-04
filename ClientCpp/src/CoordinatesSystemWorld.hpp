//
// Created by iamze on 04/03/2023.
//

#ifndef CLIENTCPP_COORDINATESSYSTEMWORLD_HPP
#define CLIENTCPP_COORDINATESSYSTEMWORLD_HPP

#pragma once
#include "CoordinatesSystem.hpp"

class CoordinatesSystemWorld : public CoordinatesSystem {
protected:
    static CoordinatesSystemWorld * m_csw;

    CoordinatesSystemWorld() {

    }

    ~CoordinatesSystemWorld(){
        delete m_csw;
    }

public:

    static CoordinatesSystemWorld * GetInstance() {
        if (m_csw == nullptr) {
            m_csw = new CoordinatesSystemWorld();
        }
        return m_csw;
    }

    /**
     *
     * @param form
     */
    virtual void AddForm(Form * form) {
        if (form == nullptr) cerr << "Fail to add form" << endl;
        else v_form.push_back(form);
    }

    /**
     *
     * @param form
     */
    virtual void RemoveForm(int i) {
        if (i < 0 || i > v_form.size()) cerr << "CoordinatesSystemWorld : remove index Out of Range" << endl;
        else v_form.erase(v_form.begin() + i);
    }

    virtual operator string() const {
        ostringstream oss;
        for (int i = 0; i < v_form.size(); i++) {
            oss << *(v_form[i]);
            if (i != v_form.size() - 1) oss << ":";
        }
        return oss.str();
    }
};


#endif //CLIENTCPP_COORDINATESSYSTEMWORLD_HPP
