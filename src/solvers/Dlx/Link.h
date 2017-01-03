#ifndef LINK_H
#define LINK_H

typedef unsigned int ui;
typedef unsigned short us;

typedef struct Link {
    Link *left;
    Link *right;
    Link *up;
    Link *down;

    Link *coln;

    ui name;
    us size;
}* node;



#endif /* end of include guard: LINK_H */
