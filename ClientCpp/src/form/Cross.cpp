//
// Created by iamze on 12/12/2022.
//

#include "../../include/VisitorForme.hpp"
#include "../../include/form/Cross.hpp"

void Cross::accept(const VisitorForme * vf) const {
    vf->visite(this);
}