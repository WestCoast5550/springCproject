#ifndef RECURSIVETEMPLATE_QBOUNDARYCONSTRAINT_H
#define RECURSIVETEMPLATE_QBOUNDARYCONSTRAINT_H

#include "Constraint.h"
#include <vector>

class QBoundaryConstraint : Constraint<int> {
    bool CheckConstraint(std::vector<int *> path, int *newItem) override {

        for (int i = 0; i < path.size(); ++i) {

            if (*(newItem) == *(path[i]) || *(newItem) + path.size() == *(path[i]) ||
                *(newItem) - path.size() == *(path[i])) {
                return false;
            }
        }
        return true;
    }
};

#endif //RECURSIVETEMPLATE_QBOUNDARYCONSTRAINT_H
