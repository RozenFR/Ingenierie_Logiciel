//
// Created by iamze on 23/02/2023.
//

#include "VisitorForme.hpp"
#include "Rect.hpp"

void Rect::accept(const VisitorForme *vf) const {
    vf->visite(this);
}