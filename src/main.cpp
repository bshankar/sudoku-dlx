#include "problems/Sudoku.h"
#include "solvers/Dlx.h"

using namespace std;


int main(int argc, char* argv[]) {
    string puzzle = argv[1];
    Sudoku sudoku(3);
    Dlx dlx(&sudoku, puzzle);
    dlx.solve();
}
