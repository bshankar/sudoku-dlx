#include "problems/Sudoku/LatinSquare.h"
#include "solvers/Dlx/Dlx.h"

using namespace std;


int main(int argc, char* argv[]) {
    LatinSquare ls(9, LatinSquare::BLOCKS);
    Dlx solver(&ls, argv[1]);
    solver.solve();
}
