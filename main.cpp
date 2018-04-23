#include <iostream>
#include "ProblemSolver.h"
#include "NQueensBoundaryConstraint.h"
#include "KnapsackBoundaryConstraint.h"
#include "NQueensLeafConstraint.h"
#include "KnapsackLeafConstrait.h"


int main() {
    ProblemSolver<4, int, NQueensBoundaryConstraint, NQueensLeafConstraint, void> nQueensProblemSolver;
    std::vector<int *> items(4);
    for (int i = 0; i < 4; ++i) {
        items[i] = new int(i);
    }

    NQueensBoundaryConstraint *nQueenBoundaryConstraint = new NQueensBoundaryConstraint();
    NQueensLeafConstraint *nQueensLeafConstraint = new NQueensLeafConstraint();

    std::vector<std::vector<int *>> result = nQueensProblemSolver.Solve(items, nQueenBoundaryConstraint, nQueensLeafConstraint, new int(4));

    if (result.size() == 0) {
        std::cout << "No solutions found" << std::endl;
    } else {
        for (int i = 0; i < result.size(); ++i) {

            for (auto const& c : result[i])
                std::cout << *c << ' ';
            std::cout << std::endl;
        }
    }

    ProblemSolver<10, KnapsackEntity, KnapsackBoundaryConstraint, void, int> knapsackProblemSolver;
    KnapsackBoundaryConstraint * knapsackBoundaryConstraint = new KnapsackBoundaryConstraint();
    KnapsackLeafConstraint * knapsackLeafConstraint = new KnapsackLeafConstraint();
    std::vector<KnapsackEntity *> knapsackEntities(10);
    for (int i = 0; i < 10; ++i) {
        knapsackEntities[i] = new KnapsackEntity(i * 2, (i | (i*3)));
    }
    std::vector<std::vector<KnapsackEntity *>> knapsackResult = knapsackProblemSolver.Solve(knapsackEntities, knapsackBoundaryConstraint,
                                                                                 knapsackLeafConstraint, new int(30));

    if (knapsackResult.size() == 0) {
        std::cout << "No solutions found" << std::endl;
    } else {
        for (int i = 0; i < knapsackResult.size(); ++i) {

            for (auto const& c : knapsackResult[i])
                std::cout << c->getCost() << ' ';
            std::cout << std::endl;
        }
    }
    return 0;
}

