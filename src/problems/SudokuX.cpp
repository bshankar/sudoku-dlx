
#include "SudokuX.h"


SudokuX::SudokuX(ui n) : Sudoku(n) {
    colns += 2*digits;
    matrix.resize(rows, vector<bool>(colns));

    // fill with normal sudoku rules
    fillMatrix();

    // Additional diagonal constraints
    for (ui c = 0; c < digits; ++c)
        for (ui k = 0; k < digits; ++k) {
            ui diagRow = c*(digits + 1)*digits + k;
            ui antiDiagRow = (c + 1)*(digits - 1)*digits + k;

            matrix[diagRow][4*cells + k] = 1;
            matrix[antiDiagRow][4*cells + digits + k] = 1;
        }
}
