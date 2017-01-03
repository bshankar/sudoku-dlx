#include "problems/SudokuX.h"
#include "solvers/Dlx.h"

using namespace std;


int main(int argc, char* argv[]) {

    SudokuX sudokux(6);
    if (argc == 2) {
        string puzzle = argv[1];
        Dlx dlx(&sudokux, puzzle);
        dlx.solve();
    } else {
        Dlx dlx(&sudokux);
        dlx.solve();
    }
}
