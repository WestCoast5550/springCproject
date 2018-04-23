//
// Created by Ринат Гумаров on 23/04/2018.
//

#ifndef RECURSIVETEMPLATE_NQUEENSLEAFCONSTRAINT_H
#define RECURSIVETEMPLATE_NQUEENSLEAFCONSTRAINT_H

#include "Constraint.h"
#include <vector>

class NQueensLeafConstraint : public Constraint<int, int> {
    bool CheckConstraint(std::vector<int *> path, int *newItem, int *size) override {
        return path.size() >= *size - 1;
    }

};

#endif //RECURSIVETEMPLATE_NQUEENSLEAFCONSTRAINT_H
