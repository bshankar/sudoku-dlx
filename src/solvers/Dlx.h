#ifndef DLX_H
#define DLX_H

#include "../problems/Problem.h"

#define INFTY 500000

/* Dancing links solver */


class Dlx {
public:
    Dlx(Problem *puzzle);
    Dlx(Problem *puzzle, string puzzleInstance);
    void initLinks(const vvb& matrix);
    ~Dlx();

    node chooseColn();
    void cover(node c);
    void uncover(node c);
    void search(ui depth);
    void printSolution();

    void coverColns(vector<ui> colns);
    void uncoverColns(vector<ui> colns);
    ui prepare(vector<ui> v, string puzzleInstance);
    void reset(vector<ui> v);
    void solve();

    node getRoot();
private:
    Problem *puzzle;

    string puzzleInstance;
    int solutions = 0;
    vector<node> solution;
    node root;
    vector<node> colnHeaders;
    ui minSize;
};

#endif /* end of include guard: DLX_H */
