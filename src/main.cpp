#include "problems/SudokuX.h"
#include "solvers/Dlx.h"

using namespace std;


int main(int argc, char* argv[]) {
    string puzzle = argv[1];
    SudokuX sudokux(3);
    Dlx dlx(&sudokux, puzzle);
    dlx.solve();
}
