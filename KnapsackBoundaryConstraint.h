#ifndef RECURSIVETEMPLATE_KNAPSACKBOUNDARYCONSTRAINT_H
#define RECURSIVETEMPLATE_KNAPSACKBOUNDARYCONSTRAINT_H

#include "Constraint.h"
#include "KnapsackEntity.h"
#include <vector>

class KnapsackBoundaryConstraint : public Constraint<KnapsackEntity, int> {
    bool CheckConstraint(std::vector<KnapsackEntity *> path, KnapsackEntity *newItem, int *c) override {

        int currentWeight = 0;
        for (int i = 0; i < path.size(); ++i) {
            currentWeight += path[i]->getWeight();
        }

        if (currentWeight + newItem->getWeight() > *c) {
            return false;
        }

        for (int i = 0; i < path.size(); ++i) {
            if (*(newItem) == *(path[i])) {
                return false;
            }
        }
        return true;
    }

};

#endif RECURSIVETEMPLATE_KNAPSACKBOUNDARYCONSTRAINT_H
