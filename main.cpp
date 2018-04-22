#include <iostream>
#include "ProblemSolver.h"
#include "Constraint.h"
#include "QBoundaryConstraint.h"


int main() {
    ProblemSolver<4, int, QBoundaryConstraint, QBoundaryConstraint> problemSolver;
    std::vector<int *> items(4);
    for (int i = 0; i < 4; ++i) {
        items[i] = new int(i);
    }

    QBoundaryConstraint *boundaryConstraint = new QBoundaryConstraint();

    std::vector<int *> result = problemSolver.Solve(items, boundaryConstraint);

    if (result.size() == 0) {
        std::cout << "No solutions found" << std::endl;
    } else {
        for (int i = 0; i < result.size(); ++i) {

            std::cout << "Result is - " << result[i] << std::endl;
        }
    }
    return 0;
}