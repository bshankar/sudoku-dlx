#ifndef LATINSQUARE_H
#define LATINSQUARE_H

#include "Problem.h"
/*
 * Generalized definition of NxN Sudoku puzzle
 * in terms of exact cover problem
 */

class LatinSquare : public Problem {
public:
    // nxn latin squares grid
    LatinSquare(ui n);

    void fillMatrix();

    // printSolution function for this problem
    void printSolution(vector<node> nodes);
    vector<ui> colnsToCover();

};


#endif /* end of include guard: LATINSQUARE_H */
