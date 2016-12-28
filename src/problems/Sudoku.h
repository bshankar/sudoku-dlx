#ifndef SUDOKU_H
#define SUDOKU_H

#include "Problem.h"
/*
 * Generalized definition of NxN Sudoku puzzle
 * in terms of exact cover problem
 */

class Sudoku : public Problem {
public:
    // fill the matrix
    Sudoku(ui n);

    // printSolution function for this problem
    void printSolution(vector<node> nodes);
    vector<ui> colnsToCover(string puzzle);
    ui getRow(ui index, us value);

private:
    ui n, cells, digits;
};


#endif /* end of include guard: SUDOKU_H */
