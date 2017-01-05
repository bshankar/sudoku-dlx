#ifndef LATINSQUARE_H
#define LATINSQUARE_H

#include "../Problem.h"

/*
 * nxn latin squares puzzle
 * in terms of exact cover problem
 */

class LatinSquare : public Problem {
public:
    LatinSquare(ui n, uint64_t extraRegions = 0);

    // printSolution function for this problem
    void printSolution(vector<node> nodes);

    // get all j where matrix[i] is 1
    vector<ui> getColns(ui i);

    // sets the number of columns based on extra regions
    void setColns();

    // list of columns to cover based on this->puzzle
    vector<ui> colnsToCover();

    // extra regions
    static const uint64_t BLOCKS = 0b1,
                          DIAG = 0b10,
                          ASTERISK = 0b100,
                          PERCENT = 0b1000,
                          CENTERDOT = 0b10000,
                          HYPER = 0b100000,
                          SQUIGGLY = 0b1000000,
                          IRREGUAR = 0b10000000;

    // extra constraints
    static const uint64_t CHESS = 0b1,
                          NONCONS = 0b10,
                          BOSSDOKU = 0b100;
    // given types
    static const uint64_t GIVENS = 0b1,
                          SUM = 0b10,
                          GREATER = 0b100;

private:
    // no of cells, height and width of a block (if it exists)
    ui cells, h, w;
    us constraintTypes;
    uint64_t extraRegions, extraConstraints, givenType;
};


#endif /* end of include guard: LATINSQUARE_H */
