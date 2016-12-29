
#include "SudokuX.h"


SudokuX::SudokuX(ui n) : Sudoku(n) {
    colns += 2*digits;

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


vector<ui> SudokuX::colnsToCover() {
    vector<ui> v = Sudoku::colnsToCover();

    // additional columns to cover
    for (ui c = 0; c < digits; ++c) {
        char diagCellValue = puzzle[c*(digits + 1)],
             antiDiagCellValue = puzzle[(c + 1)*(digits - 1)];

        if (!isEmptyCell(diagCellValue))
            v.push_back(4*cells + diagCellValue - '1');

        if (!isEmptyCell(antiDiagCellValue))
            v.push_back(4*cells + digits +  antiDiagCellValue - '1');
    }
    return v;
}
