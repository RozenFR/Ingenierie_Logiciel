//
// Created by iamze on 23/02/2023.
//

#include "visitor/VisitorForm.hpp"
#include "Rect.hpp"

void Rect::accept(VisitorForm *vf) {
    vf->visite(this);
}