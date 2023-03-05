//
// Created by iamze on 28/02/2023.
//

#ifndef CLIENTCPP_COORDINATESSYSTEMSCREEN_HPP
#define CLIENTCPP_COORDINATESSYSTEMSCREEN_HPP

#pragma once
#include "CoordinatesSystem.hpp"
#include "../form/visitor/CoordinatesConverter.hpp"

/**
 * Class managing Coordinates in the Screen
 */
class CoordinatesSystemScreen : public CoordinatesSystem {
protected:
    // Static var representing singleton
    static CoordinatesSystemScreen * m_css;
    // Attrute representing the functionality to convert coordinates in a specific frames
    CoordinatesConverter * m_cc;

    /**
     * Constructor of CoordinatesSystemScreen
     */
    CoordinatesSystemScreen() {

    }

    /**
     * Constructor CoordinatesSystemScreen
     * @param cc Coordinates Converter
     */
    CoordinatesSystemScreen(CoordinatesConverter * cc) {
        m_cc = cc;
    }

    /**
     * Destroyer of CoordinatesSystemScreen
     */
    ~CoordinatesSystemScreen() {
        delete m_css;
    }

public:
    /**
     * Constructor by copy deleted because Singleton
     * @param css
     */
    CoordinatesSystemScreen(CoordinatesSystemScreen * css) = delete;

    /**
     * Method to get Instance of Class
     * @return Singleton
     */
    static CoordinatesSystemScreen * GetInstance() {
        if (m_css == nullptr)
            throw Error("CoordinatesSystemScreen : Can't get Instance because Converter is not initialized in class.");
        return m_css;
    }

    /**
     * Method to get Instance of Class
     * @param cc coordinates converter
     * @return Singleton
     */
    static CoordinatesSystemScreen * GetInstance(CoordinatesConverter * cc) {
        if (m_css == nullptr)
            m_css = new CoordinatesSystemScreen(cc);
        return m_css;
    }

    /**
     * method to add form\n
     * - We need to convert coordinates for screen
     * @param form form to add
     */
    virtual void AddForm(Form * form) {
        if (form == nullptr) cerr << "Fail to add form" << endl;
        else {
            form->accept(m_cc);
            v_form.push_back(form);
        }
    }

    /**
     * Method to remove a form
     * @param i index of form in vector
     */
    virtual void RemoveForm(int i) {
        if (i < 0 || i > v_form.size()) cerr << "CoordinatesSystemScreen : remove index Out of Range" << endl;
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


#endif //CLIENTCPP_COORDINATESSYSTEMSCREEN_HPP
