//
// Created by iamze on 23/02/2023.
//

#include "../../include/VisitorForme.hpp"
#include "../../include/form/Rectangle.hpp"

void Rectangle::accept(const VisitorForme *vf) const {
    vf->visite(this);
}