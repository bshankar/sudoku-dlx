#ifndef LATINSQUARE_H
#define LATINSQUARE_H

#include "../Problem.h"
#include <map>

/*
 * nxn latin squares puzzle
 * in terms of exact cover problem
 */

class LatinSquare : public Problem {
public:
    LatinSquare(ui n);

    // printSolution function for this problem
    void printSolution(vector<node> nodes);

    // get the value of matrix[i][j]
    bool get(ui i, ui j);

    // list of columns to cover based on this->puzzle
    vector<ui> colnsToCover();

private:
    ui cells;
    // any extra regions for variants
    vector<vector<ui>> extraRegions;
};


#endif /* end of include guard: LATINSQUARE_H */
