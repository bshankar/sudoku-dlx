#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
typedef unsigned int ui;
typedef unsigned short us;


typedef struct link {
    link *left;
    link *right;
    link *up;
    link *down;

    link *coln;

    ui name;
    ui size;
}* node;


class Problem {
public:

    Problem() {}

    virtual bool get(ui i, ui j) {
        return true;
    }

    virtual void printSolution(vector<node> nodes) {
        cout << nodes[0]->name << endl;
    }


    virtual vector<ui> colnsToCover() {
        vector<ui> v;
        return v;
    }

    virtual ui getRow(ui index, us value) {
        return 0;
    }


    bool isEmptyCell(char c) {
        return c == '.' || c == '0';
    }

    void setPuzzle(string p) {
        puzzle = p;
    }

    ui getCells() {
        return cells;
    }

protected:
    vvb matrix;
    int rows, colns;
    string puzzle;
    ui n, cells, digits;
};

#endif /* end of include guard: PROBLEM_H */
