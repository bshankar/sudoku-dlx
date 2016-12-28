#include "Sudoku.h"
#include <assert.h>


Sudoku::Sudoku(ui n)
    : n(n), cells(n*n*n*n), digits(n*n) {

    int constraintSets = 4;
    rows = cells*digits;
    colns = constraintSets*cells;

    matrix.resize(rows, vector<bool>(colns));

    // construct the matrix for n^2xn^2 sudoku
    for (ui c = 0; c < cells; ++c) {
        for (ui k = 0; k < digits; ++k) {

            us row = c*digits + k;

            matrix[row][c] = 1;
            matrix[row][c/digits*digits + cells + k] = 1;
            matrix[row][c%digits*digits + 2*cells + k] = 1;
            matrix[row][(c/n - c/digits*n + c/(n*digits)*n)*digits + 3*cells
                        + k]
                = 1;
        }
    }
}


void Sudoku::printSolution(vector<node> nodes) {
    int i = 0;

    while (nodes[i]) {
        char value = nodes[i]->name % digits + '1';
        int pos = nodes[i]->name / digits;

        puzzle[pos] = value;
        ++i;
    }
    cout << puzzle << endl;
}


vector<ui> Sudoku::colnsToCover(string puzzle) {
    assert(puzzle.size() == cells);

    vector<ui> ctc;
    for (us cell = 0; cell < cells; ++cell) {

        if (puzzle[cell] != '0' && puzzle[cell] != '.') {
            us d = puzzle[cell] - '1';

            // indices of covered colns
            us c1 = cell;
            us c2 = cell/digits*digits + cells + d;
            us c3 = cell%digits*digits + 2*cells + d;
            us c4 = (cell/n - cell/digits*n + cell/(n*digits)*n)*digits +
                    3*cells + d;

            ctc.push_back(c1);
            ctc.push_back(c2);
            ctc.push_back(c3);
            ctc.push_back(c4);
        }
    }
    return ctc;
}


ui Sudoku::getRow(ui index, us value) {
    return index*digits + value;
}
