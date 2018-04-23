#ifndef RECURSIVETEMPLATE_QBOUNDARYCONSTRAINT_H
#define RECURSIVETEMPLATE_QBOUNDARYCONSTRAINT_H

#include "Constraint.h"
#include <vector>

class NQueensBoundaryConstraint : public Constraint<int, void > {
    bool CheckConstraint(std::vector<int *> path, int *newItem, void *) override {

        for (int i = 0; i < path.size(); ++i) {
            if (*(newItem) == *(path[i]) ||
                    abs((int)(*(newItem) - *(path[i]))) == abs((int)(path.size() - i))) {
                return false;
            }
        }
        return true;
    }

};

#endif //RECURSIVETEMPLATE_QBOUNDARYCONSTRAINT_H
