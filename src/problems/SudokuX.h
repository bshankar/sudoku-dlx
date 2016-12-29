#ifndef SUDOKUX_H
#define SUDOKUX_H


#include "Sudoku.h"


class SudokuX : public Sudoku {
public:
    SudokuX(ui n);
    vector<ui> colnsToCover();
};

#endif /* end of include guard: SUDOKUX_H */
