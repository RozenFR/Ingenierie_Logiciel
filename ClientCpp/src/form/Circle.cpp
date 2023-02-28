//
// Created by iamze on 14/12/2022.
//

#include "visitor/VisitorForm.hpp"
#include "Circle.hpp"

void Circle::accept(VisitorForm *vf) {
    vf->visite(this);
}