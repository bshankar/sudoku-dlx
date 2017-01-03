#ifndef PROBLEM_H
#define PROBLEM_H

#include "../solvers/Dlx/Link.h"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;
typedef unsigned int ui;
typedef unsigned short us;

// A very generalized framework to solve
// exact cover problems with focus on number placement puzzle
// like sudoku

class Problem {
public:

    Problem() {}

    virtual bool get(ui i, ui j) {
        // get the value at matrix[i][j]
        return true;
    }

    // dummy function to print the solution
    // will be overwritten
    virtual void printSolution(vector<node> nodes) {}


    // dummy function to get columns to cover
    // based on puzzle. will be overwritten
    virtual vector<ui> colnsToCover() {
        vector<ui> v;
        return v;
    }

    // get the row number based on some numbers
    // dummy: will be overwritten
    virtual ui getRow(ui index, us value) {
        return 0;
    }


    bool isEmptyCell(char c) {
        // empty cells are indicated with a "." or a "0"
        return c == '.' || c == '0';
    }

    void setPuzzle(string p) {
        puzzle = p;
    }

    // get the number of cells of a sudoku (like) puzzle
    ui getCells() {
        return digits*digits;
    }

    ui getRows() {
        return rows;
    }

    ui getColns() {
        return colns;
    }

protected:
    // number of rows and columns of boolean matrix
    // that needs to be covered exactly.
    ui rows, colns;
    // some puzzles like sudoku have givens
    // which are provided in the puzzle
    string puzzle;
    // digits x digits grid
    ui digits;
};

#endif /* end of include guard: PROBLEM_H */
