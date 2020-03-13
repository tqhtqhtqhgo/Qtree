//
// Created by caaffrey on 2020/3/6.
//
#include <bits/types/FILE.h>

#ifndef QTREE_TREESTRUCTURE_H
#define QTREE_TREESTRUCTURE_H
#endif //QTREE_TREESTRUCTURE_H
struct qnode {
    int flag;
    int level;
    double xy[2];
    struct qnode *child[4];
};
typedef struct qnode Node;
