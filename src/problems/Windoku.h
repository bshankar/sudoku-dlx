#ifndef WINDOKU_H
#define WINDOKU_H

#include "Sudoku.h"

class Windoku : public Sudoku {
public:
    Windoku(ui n);
    vector<ui> colnsToCover();
};

#endif /* end of include guard: WINDOKU_H */
