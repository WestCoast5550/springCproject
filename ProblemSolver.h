#ifndef RECURSIVETEMPLATE_PROBLEMSOLVER_H
#define RECURSIVETEMPLATE_PROBLEMSOLVER_H

#include <vector>
#include "Constraint.h"

template<int N, class ITEM_TYPE, class B_CONSTRAINT, class L_CONSTRAINT, class CONSTRAINT>
class ProblemSolver {
private:
    std::vector<ITEM_TYPE *> items;
    Constraint<ITEM_TYPE, CONSTRAINT> *bConstraint;
    Constraint<ITEM_TYPE, CONSTRAINT> *lConstraint;
    CONSTRAINT * c;
    std::vector<std::vector<ITEM_TYPE *>> result;

    std::vector<ITEM_TYPE *> findSolution(std::vector<ITEM_TYPE *> currentPath, int pathSize, ITEM_TYPE *newItem, CONSTRAINT *c) {
        std::vector<ITEM_TYPE *> path;
        path.reserve((unsigned long) N);
        if (currentPath.size() != 0) {
            for (int i = 0; i < currentPath.size(); ++i) {
                path.insert(path.begin() + i, currentPath[i]);
            }
        }

        if (lConstraint->CheckConstraint(path, newItem, c)) {

            if ((bConstraint->CheckConstraint(path, newItem, c))
                && (lConstraint == nullptr || lConstraint->CheckConstraint(path, newItem, c))) {
                path.insert(path.begin() + pathSize, newItem);
                return path;
            }
        } else {
            if (bConstraint->CheckConstraint(path, newItem, c)) {

                path.insert(path.begin() + pathSize, newItem);
                for (int i = 0; i < items.size(); ++i) {
                    std::vector<ITEM_TYPE *> possibleSolution = findSolution(path, pathSize + 1, items[i], c);
                    if (possibleSolution.size() == 0)
                        continue;
                    return possibleSolution;
                }
            }

        }
        return std::vector<ITEM_TYPE *>();
    }

public:
    std::vector<std::vector<ITEM_TYPE *>> Solve(std::vector<ITEM_TYPE *> items, B_CONSTRAINT *boundaryConstraint,
                                   L_CONSTRAINT *leafConstraint, CONSTRAINT *c) {
        this->items = items;
        if (Constraint<ITEM_TYPE, CONSTRAINT> *bc = reinterpret_cast<Constraint<ITEM_TYPE, CONSTRAINT> *>(boundaryConstraint)) {
            Constraint<ITEM_TYPE, CONSTRAINT> *lc = reinterpret_cast<Constraint<ITEM_TYPE, CONSTRAINT> *>(leafConstraint);
            if (lc) {

                bConstraint = bc;
                lConstraint = lc;

                for (int i = 0; i < items.size(); i++) {
                    auto path = findSolution(std::vector<ITEM_TYPE *>(), 0, items[i], c);
                    if (path.size() == 0) {
                        continue;
                    }
                    this->result.push_back(path);
                }
            }
        }
        return result;
    }
};


#endif //RECURSIVETEMPLATE_PROBLEMSOLVER_H
