
#include "LatinSquare.h"
#include "../../utils/factorize.h"
#include <string.h>


LatinSquare::LatinSquare(ui n, uint64_t extraRegions)
    : extraRegions(extraRegions) {
    this->digits = n;
    cells = digits*digits;
    rows = cells*digits;
    setColns();


    h = factor(digits);
    w = digits/h;
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
        if (extraRegions & PERCENT)
            colns += 3*digits;
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
    ui offset = 3*cells;

    // add any extra constraints
    if (extraRegions) {
        if (extraRegions & BLOCKS) {
            // try to add blocks (becomes sudoku)

            if (h != 1) {
                // we can create blocks
                ui block = w*(row / h) + coln / w;
                colnsVec.push_back(block*digits + value + offset);
                offset += cells;
            }
        }

        if (extraRegions & DIAG) {
            if (i % (digits + 1) == 0)
                // i belongs to the diagonal
                colnsVec.push_back(value + offset);
            if (i % (digits - 1) == 0 && i)
                // i belongs to the anti diagonal
                colnsVec.push_back(digits + value + offset);
            offset += 2*digits;
        }

        if (extraRegions & CENTERDOT) {
            if (h & 1 && w & 1) {
                // possible to create center dots
                if (row % h == h/2 && coln % w == w/2)
                    colnsVec.push_back(value + offset);
                offset += digits;
            }
        }

        if (extraRegions & ASTERISK) {
        }

        if (extraRegions & PERCENT) {
            if (h != 1) {
                if (i % (digits - 1) == 0 && i)
                    // anti diagonal
                    colnsVec.push_back(value + offset);

                if (row && row < 1 + h && coln && coln < 1 + w)
                    // first block
                    colnsVec.push_back(digits + value + offset);

                if (row < (digits - 1) && row >= (digits - 1 - h) &&
                        coln < (digits - 1) && coln >= (digits - 1 - w))
                    // 2nd block
                    colnsVec.push_back(2*digits + value + offset);

                offset += 3*digits;
            }
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
    for (ui i = 0; i < cells; ++i) {

        if (!isEmptyCell(puzzle[i])) {
            us d = puzzle[i] - '1';

            // indices of covered colns
            us c1 = i;
            us c2 = i/digits*digits + cells + d;
            us c3 = i%digits*digits + 2*cells + d;

            ctc.push_back(c1);
            ctc.push_back(c2);
            ctc.push_back(c3);

            ui offset = 3*cells;

            if (extraRegions) {
                if (extraRegions & BLOCKS) {
                    // try to add blocks (becomes sudoku)

                    if (h != 1) {
                        // we can create blocks
                        ui block = w*((i/digits) / h) + (i % digits) / w;
                        ctc.push_back(block*digits + d + offset);
                        offset += cells;
                    }
                }
            }

        }
    }
    return ctc;
}
