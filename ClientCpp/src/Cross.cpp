//
// Created by iamze on 12/12/2022.
//

#include "VisitorForme.hpp"
#include "Cross.hpp"

void Cross::accept(const VisitorForme * vf) const {
    vf->visite(this);
}