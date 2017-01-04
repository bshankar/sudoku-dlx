
#include "LatinSquare.h"
#include "../../utils/factorize.h"
#include <string.h>


LatinSquare::LatinSquare(ui n, uint64_t extraRegions)
    : extraRegions(extraRegions) {
    this->digits = n;
    cells = digits*digits;
    rows = cells*digits;
    setColns();
}


void LatinSquare::setColns() {
    constraintTypes = 3;
    colns = constraintTypes*cells;

    if (extraRegions) {
        if (extraRegions & BLOCKS)
            colns += cells;
        if (extraRegions & DIAG)
            colns += 2*digits;
        if (extraRegions & CENTERDOT)
            colns += digits;
        if (extraRegions & ASTERISK)
            colns += digits;
        /* if (extraRegions & HYPER) */
        /* colns += */
    }
}


vector<ui> LatinSquare::getColns(ui i) {
    ui cell = i / digits,
       value = i % digits;
    ui row = cell / digits,
       coln = cell % digits;

    vector<ui> colnsVec = {cell, row*digits + value + cells, coln*digits + value + 2*cells};

    // add any extra constraints
    if (extraRegions) {
        if (extraRegions & BLOCKS) {
            // try to add blocks (becomes sudoku)
            ui h = factor(digits);
            ui w = digits/h;

            if (h != 1) {
                // we can create blocks
                ui block = w*(row / h) + coln / w;
                colnsVec.push_back(block*digits + value + 3*cells);
            }
        }

        if (extraRegions & DIAG) {
            // add diagonals
        }

        if (extraRegions & CENTERDOT) {
            // add center dots
        }

        if (extraRegions & ASTERISK) {
            // add asterisk
        }

        if (extraRegions & PERCENT) {
            // add percent regions
        }

        if (extraRegions & HYPER) {
            // add Hypersudoku regions
        }
    }

    return colnsVec;
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
