//
// Created by iamze on 28/02/2023.
//

#ifndef CLIENTCPP_COORDINATESSYSTEMSCREEN_HPP
#define CLIENTCPP_COORDINATESSYSTEMSCREEN_HPP

#pragma once
#include "CoordinatesSystem.hpp"
#include "form/visitor/CoordinatesConverter.hpp"

class CoordinatesSystemScreen : public CoordinatesSystem {
protected:
    static CoordinatesSystemScreen * m_css;
    CoordinatesConverter * m_cc;

    CoordinatesSystemScreen() {

    }

    CoordinatesSystemScreen(CoordinatesConverter * cc) {
        m_cc = cc;
    }

    ~CoordinatesSystemScreen() {
        delete m_css;
    }

public:

    static CoordinatesSystemScreen * GetInstance() {
        if (m_css == nullptr)
            throw Error("CoordinatesSystemScreen : Can't get Instance because Converter is not initialized in class.");
        return m_css;
    }

    static CoordinatesSystemScreen * GetInstance(CoordinatesConverter * cc) {
        if (m_css == nullptr)
            m_css = new CoordinatesSystemScreen(cc);
        return m_css;
    }

    /**
     *
     * @param form
     */
    virtual void AddForm(Form * form) {
        if (form == nullptr) cerr << "Fail to add form" << endl;
        else {
            form->accept(m_cc);
            v_form.push_back(form);
        }
    }

    /**
     *
     * @param form
     */
    virtual void RemoveForm(int i) {
        if (i < 0 || i > v_form.size()) cerr << "CoordinatesSystemScreen : remove index Out of Range" << endl;
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


#endif //CLIENTCPP_COORDINATESSYSTEMSCREEN_HPP
