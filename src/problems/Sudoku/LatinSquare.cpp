
#include "LatinSquare.h"
#include <string.h>


LatinSquare::LatinSquare(ui n) {
    digits = n;
    cells = digits*digits;
    rows = cells*digits;
    colns = 3*cells;
}


vector<ui> LatinSquare::getColns(ui i) {
    ui cell = i / digits,
       value = i % digits;
    ui row = cell / digits,
       coln = cell % digits;

    return {cell, row*digits + value + cells, coln*digits + value + 2*cells};
}



void LatinSquare::printSolution(vector<node> nodes) {
    ui i = 0;
    ui cells = digits*digits;
    char sol[cells];
    strcpy(sol, puzzle.c_str());

    while (nodes[i]) {
        char value = nodes[i]->name % digits + '1';
        int pos = nodes[i]->name / digits;

        sol[pos] = value;
        ++i;
    }

    // print the solution
    for (ui j = 0; j < getCells(); ++j)
        cout << sol[j];
    cout << endl;
}


vector<ui> LatinSquare::colnsToCover() {
    vector<ui> ctc;
    for (us cell = 0; cell < cells; ++cell) {

        if (!isEmptyCell(puzzle[cell])) {
            us d = puzzle[cell] - '1';

            // indices of covered colns
            us c1 = cell;
            us c2 = cell/digits*digits + cells + d;
            us c3 = cell%digits*digits + 2*cells + d;

            ctc.push_back(c1);
            ctc.push_back(c2);
            ctc.push_back(c3);
        }
    }
    return ctc;
}
