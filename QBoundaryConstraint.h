#ifndef RECURSIVETEMPLATE_QBOUNDARYCONSTRAINT_H
#define RECURSIVETEMPLATE_QBOUNDARYCONSTRAINT_H

#include "Constraint.h"
#include <vector>

class QBoundaryConstraint : public Constraint<int> {
    bool CheckConstraint(std::vector<int *> path, int *newItem) override {

        for (int i = 0; i < path.size(); ++i) {
            abs(-7);
            if (*(newItem) == *(path[i]) ||
                    abs((int)(*(newItem) - *(path[i]))) == abs((int)(path.size() - i))) {
                return false;
            }
        }
        return true;
    }

    bool checkDaigonal(int size, int num) {

    }

};

#endif //RECURSIVETEMPLATE_QBOUNDARYCONSTRAINT_H
