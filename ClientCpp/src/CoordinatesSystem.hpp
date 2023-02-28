//
// Created by iamze on 28/02/2023.
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
#include "form/Form.hpp"
#include "form/visitor/CoordinatesConverter.hpp"

using namespace std;

class CoordinatesSystem {
protected:
    static CoordinatesSystem * m_cs;
    CoordinatesConverter * m_cc;

    double m_ix = 1;
    double m_iy = 0;
    double m_jx = 0;
    double m_jy = 1;

    vector<Form *> v_form;

    CoordinatesSystem() {

    }

    CoordinatesSystem(CoordinatesConverter * cc) {
        m_cc = cc;
    }

public:

    static CoordinatesSystem * GetInstance() {
        if (m_cs == nullptr) {
            m_cs = new CoordinatesSystem();
        }
        return m_cs;
    }

    static CoordinatesSystem * GetInstance(CoordinatesConverter * cc) {
        if (m_cs == nullptr) {
            m_cs = new CoordinatesSystem(cc);
        }
        return m_cs;
    }

    ~CoordinatesSystem() {
        for (int i = 0; i < v_form.size(); i++) {
            delete v_form[i];
        }
    }

    /**
     *
     * @param x
     */
    void setix(const double x) {
        m_ix = x;
    }

    /**
     *
     * @param y
     */
    void setiy(const double y) {
        m_iy = y;
    }

    /**
     *
     * @param x
     */
    void setjx(const double x) {
        m_jx = x;
    }

    /**
     *
     * @param y
     */
    void setjy(const double y) {
        m_jy = y;
    }

    /**
     *
     * @return
     */
    double getix() {
        return m_ix;
    }

    /**
     *
     * @return
     */
    double getiy() {
        return m_iy;
    }

    /**
     *
     * @return
     */
    double getjx() {
        return m_jx;
    }

    /**
     *
     * @return
     */
    double getjy() {
        return m_jy;
    }

    vector<Form *> getForms() {
        return v_form;
    }

    /**
     *
     * @param form
     */
    void AddForm(Form * form) {
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
    void RemoveForm(int i) {
        if (i < 0 || i > v_form.size()) cerr << "Fail to remove form : index Out of Range" << endl;
        else {
            v_form.erase(v_form.begin() + i);
        }
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

inline ostream& operator<<(ostream &os, const CoordinatesSystem &cs) {
    return os << (string) cs;
}


#endif //CLIENTCPP_COORDINATESSYSTEM_HPP
