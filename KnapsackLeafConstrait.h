//
// Created by Ринат Гумаров on 23/04/2018.
//

#ifndef RECURSIVETEMPLATE_KNAPSACKLEAFCONSTRAIT_H
#define RECURSIVETEMPLATE_KNAPSACKLEAFCONSTRAIT_H

#include "Constraint.h"
#include "KnapsackEntity.h"
#include <vector>

class KnapsackLeafConstraint : public Constraint<void , void > {
    bool CheckConstraint(std::vector<void *>, void *, void *z) override {
        return true;
    }

};

#endif //RECURSIVETEMPLATE_KNAPSACKLEAFCONSTRAIT_H
