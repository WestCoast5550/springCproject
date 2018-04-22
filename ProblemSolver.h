#ifndef RECURSIVETEMPLATE_PROBLEMSOLVER_H
#define RECURSIVETEMPLATE_PROBLEMSOLVER_H

#include <vector>
#include "Constraint.h"

template<int N, class ITEM_TYPE, class B_CONSTRAINT, class L_CONSTRAINT>
class ProblemSolver {
private:
    std::vector<ITEM_TYPE *> items;
    Constraint<ITEM_TYPE> *bConstraint;
    Constraint<ITEM_TYPE> *lConstraint;

    std::vector<ITEM_TYPE *> findSolution(std::vector<ITEM_TYPE *> currentPath, int pathSize, ITEM_TYPE *newItem) {
        std::vector<ITEM_TYPE *> path;
        path.reserve(N);
        if (currentPath.size() != 0) {
            for (int i = 0; i < currentPath.size(); ++i) {
                path[i] = currentPath[i];
            }
        }

        if (pathSize == N - 1) {

            if (lConstraint == nullptr || lConstraint->CheckConstraint(path, newItem)) {
                path[pathSize] = newItem;
                return path;
            }
        } else {
            if (bConstraint == nullptr || bConstraint->CheckConstraint(path, newItem)) {

                path[pathSize] = newItem;
                for (int i = 0; i < items.size(); ++i) {
                    std::vector<ITEM_TYPE *> possibleSolution = findSolution(path, pathSize + 1, items[i]);
                    if (possibleSolution.size() == 0)
                        continue;
                    return possibleSolution;
                }
            }

        }
        return std::vector<ITEM_TYPE *>();
    }

public:
    std::vector<ITEM_TYPE *> Solve(std::vector<ITEM_TYPE *> items, B_CONSTRAINT *boundaryConstraint = nullptr,
                                   L_CONSTRAINT *leafConstraint = nullptr) {
        this->items = items;
        if (Constraint<ITEM_TYPE> *bc = dynamic_cast<Constraint<ITEM_TYPE> *>(boundaryConstraint)) {
            Constraint<ITEM_TYPE> *lc = dynamic_cast<Constraint<ITEM_TYPE> *>(leafConstraint);
            if (lc || leafConstraint == nullptr) {

                bConstraint = bc;
                lConstraint = lc;

                for (int i = 0; i < items.size(); i++) {
                    auto path = findSolution(std::vector<ITEM_TYPE *>(), 0, items[i]);
                    if (path.size() == 0) {
                        continue;
                    }
                    return path;
                }
            }
        }
        return std::vector<ITEM_TYPE *>();
    }
};


#endif //RECURSIVETEMPLATE_PROBLEMSOLVER_H
