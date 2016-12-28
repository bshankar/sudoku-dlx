#ifndef PROBLEM_H
#define PROBLEM_H

#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
typedef unsigned int ui;
typedef unsigned short us;
typedef vector<vector<bool>> vvb;


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

    virtual vvb getMatrix() {
        return matrix;
    }

    virtual void printSolution(vector<node> nodes) {
        cout << nodes[0]->name << endl;
    }


    void printMatrix() {
        for (ui i = 0; i < matrix.size(); ++i) {
            for (ui j = 0; j < matrix[0].size(); ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    virtual vector<ui> colnsToCover(string puzzle) {
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

protected:
    vvb matrix;
    int rows, colns;
    string puzzle;
};

#endif /* end of include guard: PROBLEM_H */
