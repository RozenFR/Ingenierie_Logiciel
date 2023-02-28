//
// Created by iamze on 12/12/2022.
//

#include "visitor/VisitorForm.hpp"
#include "Cross.hpp"

void Cross::accept(VisitorForm * vf) {
    vf->visite(this);
}