//
// Created by iamze on 14/12/2022.
//

#include "VisitorForme.hpp"
#include "Circle.hpp"

void Circle::accept(const VisitorForme *vf) const {
    vf->visite(this);
}