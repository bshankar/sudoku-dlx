#include "Dlx.h"


Dlx::Dlx(Problem *prbm, string puzzle) : prbm(prbm),
    puzzle(puzzle) {

    solution.resize(3*prbm->getRows());
    initLinks();
    prbm->setPuzzle(puzzle);
}


void Dlx::initLinks() {
    // Create the data structure for the Dlx algorithm
    root  = new Link();
    node thisHead = new Link();

    const ui rows = prbm->getRows();
    const ui colns = prbm->getColns();
    colnHeaders.resize(colns);

    root->right = thisHead;
    thisHead->left = root;
    thisHead->name = 0;
    thisHead->size = 0;
    colnHeaders[0] = thisHead;

    // create and link all column headers
    for (ui i = 1; i < colns; ++i) {
        node tmpHead = new Link();
        tmpHead->name = i;
        tmpHead->size = 0;
        thisHead->right = tmpHead;
        tmpHead->left = thisHead;
        thisHead = tmpHead;
        colnHeaders[i] = thisHead;
    }

    colnHeaders[colns - 1]->right = root;
    root->left = colnHeaders[colns - 1];

    // store immediately above and left
    vector<node> above(colns);
    vector<node> before(rows);

    for (ui i = 0; i < rows; ++i) {
        vector<ui> filledColns = prbm->getColns(i);
        for (ui j: filledColns) {
            node tmpRow = new Link();
            tmpRow->name = i;
            tmpRow->coln = colnHeaders[j];
            ++tmpRow->coln->size;

            // vertical links
            if (above[j] == NULL) {
                colnHeaders[j]->down = tmpRow;
                tmpRow->up = colnHeaders[j];
            } else {
                above[j]->down = tmpRow;
                tmpRow->up = above[j];
            }
            above[j] = tmpRow;

            // horizontal links
            if (before[i] != NULL) {
                before[i]->right = tmpRow;
                tmpRow->left = before[i];
            }
            before[i] = tmpRow;
        }
    }

    // make colns circular
    for (ui i = 0; i < colns; ++i) {
        colnHeaders[i]->up = above[i];
        above[i]->down = colnHeaders[i];
    }

    // make rows circular
    for (ui i = 0; i < rows; ++i) {
        node f_row = before[i];

        while (f_row->left)
            f_row = f_row->left;

        before[i]->right = f_row;
        f_row->left = before[i];
    }
}


node Dlx::chooseColn() {

    node minColn = root->right;
    minSize = root->right->size;
    for (node cH = root->right; cH != root; cH = cH->right) {

        if (cH->size == 1) {
            minSize = 1;
            minColn = cH;
            break;
        }

        if (cH->size < minSize) {
            minColn = cH;
            minSize = cH->size;
        }
    }
    return minColn;
}


void Dlx::cover(node c) {

    // remove c from column headers
    c->left->right = c->right;
    c->right->left = c->left;

    for (node  i = c->down; i != c; i = i->down) {
        for (node j = i->right; j != i; j = j->right) {

            // remove j from its column
            j->down->up = j->up;
            j->up->down = j->down;
            --j->coln->size;
        }
    }
}


void Dlx::uncover(node c) {

    for (node  i = c->up; i != c; i = i->up) {
        for (node j = i->left; j != i; j = j->left) {
            // add back j to its column
            ++j->coln->size;
            j->up->down = j;
            j->down->up = j;
        }
    }

    // add back c to column headers
    c->left->right = c;
    c->right->left = c;
}


void Dlx::search(ui k) {

    if (solutions >= 2)
        return;

    if (root->right == root) {
        printSolution();
        ++solutions;
        return;
    }

    node c = chooseColn();
    cover(c);

    for (node  r = c->down; r != c; r = r->down) {
        solution[k] = r;

        for (node j = r->right; j != r; j = j->right)
            cover(j->coln);

        search(k+1);
        r = solution[k];
        c = r->coln;

        for (node j = r->left; j != r; j = j->left)
            uncover(j->coln);
    }
    uncover(c);
    return;
}


void Dlx::printSolution() {
    prbm->printSolution(solution);
}


node Dlx::getRoot() {
    return root;
}


void Dlx::coverColns(vector<ui> colns) {
    for (ui i: colns)
        cover(colnHeaders[i]);
}


void Dlx::uncoverColns(vector<ui> colns) {
    // uncover is done in reverse order
    for (auto i = colns.rbegin(); i != colns.rend(); ++i)
        uncover(colnHeaders[*i]);
}


void Dlx::solve() {

    if (puzzle.size() == prbm->getCells()) {
        // solve the prbm
        vector<ui> v = prbm->colnsToCover();

        coverColns(v);
        search(0);
        uncoverColns(v);
    } else {
        cout << "Solving empty puzzle!" << endl;
        search(0);
    }
}


Dlx::~Dlx() {
    // delete the data structure
    /* for (us i = 0; i < colnHeaders.size(); ++i) { */
    /*     node r = colnHeaders[i]->down; */
    /*     node tmp = r->down; */
    /*     while (r != colnHeaders[i]) { */
    /*         delete r; */
    /*         r = tmp; */
    /*         tmp = tmp->down; */
    /*     } */
    /*     delete tmp; */
    /* } */
    /* delete root; */
}
