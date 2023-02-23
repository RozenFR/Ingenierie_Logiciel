//
// Created by iamze on 14/12/2022.
//

#include "../../include/VisitorForme.hpp"
#include "../../include/form/Circle.hpp"

void Circle::accept(const VisitorForme *vf) const {
    vf->visite(this);
}