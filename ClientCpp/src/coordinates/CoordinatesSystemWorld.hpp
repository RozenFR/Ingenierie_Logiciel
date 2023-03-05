//
// Created by iamze on 04/03/2023.
//

#ifndef CLIENTCPP_COORDINATESSYSTEMWORLD_HPP
#define CLIENTCPP_COORDINATESSYSTEMWORLD_HPP

#pragma once
#include "CoordinatesSystem.hpp"

/**
 * Class managing Coordinates in the World
 */
class CoordinatesSystemWorld : public CoordinatesSystem {
protected:
    // Static var representing singleton
    static CoordinatesSystemWorld * m_csw;

    /**
     * Contructor of CoordinatesSystemWorld
     */
    CoordinatesSystemWorld() {

    }

    /**
     * Destroyer of CoordinatesSystemWorld
     */
    ~CoordinatesSystemWorld(){
        delete m_csw;
    }

public:
    /**
     * Constructor by copy deleted because Singleton
     * @param css
     */
    CoordinatesSystemWorld(CoordinatesSystemWorld * csw) = delete;

    /**
     * Method to get Instance of Class
     * @return Singleton
     */
    static CoordinatesSystemWorld * GetInstance() {
        if (m_csw == nullptr) {
            m_csw = new CoordinatesSystemWorld();
        }
        return m_csw;
    }

    /**
     * method to add form
     * @param form form to add
     */
    virtual void AddForm(Form * form) {
        if (form == nullptr) cerr << "Fail to add form" << endl;
        else v_form.push_back(form);
    }

    /**
     * Method to remove a form
     * @param i index of form in vector
     */
    virtual void RemoveForm(int i) {
        if (i < 0 || i > v_form.size()) cerr << "CoordinatesSystemWorld : remove index Out of Range" << endl;
        else v_form.erase(v_form.begin() + i);
    }

    /**
     * Overload string operator
     * @return ostream
     */
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
