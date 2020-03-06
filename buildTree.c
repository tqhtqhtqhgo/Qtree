//
// Created by caaffrey on 2020/3/6.
//
// make a node at given location (x,y) and level
#include "buildTree.h"
#include "stdlib.h"
#include "math.h"
#include "stdio.h"

Node *makeNode( double x, double y, int level ) {

    int i;

    Node *node = (Node *)malloc(sizeof(Node));

    node->level = level;

    node->xy[0] = x;
    node->xy[1] = y;

    for( i=0;i<4;++i )
        node->child[i] = NULL;

    return node;
}

// split a leaf nodes into 4 children


void makeChildren( Node *parent ) {

    double x = parent->xy[0];
    double y = parent->xy[1];

    int level = parent->level;

    double hChild = pow(2.0,-(level+1));

    parent->child[0] = makeNode( x,y, level+1 );
    parent->child[1] = makeNode( x+hChild,y, level+1 );
    parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
    parent->child[3] = makeNode( x,y+hChild, level+1 );

}
int preVisitQuadTree(Node* InRoot)
{
    if(InRoot)
    {
        printf("%f::",InRoot->xy[0]);
        printf("%f\n",InRoot->xy[1]);
        preVisitQuadTree(InRoot->child[0]);
        preVisitQuadTree(InRoot->child[1]);
        preVisitQuadTree(InRoot->child[2]);
        preVisitQuadTree(InRoot->child[3]);
    }
    return 0;
}
//int growTree(Node *head){
//    if(head)
//    {
//        growTree(head->child[0]);
//        growTree(head->child[1]);
//        growTree(head->child[2]);
//        growTree(head->child[3]);
//    }
//    else{
//        makeChildren(head);
//        return 0;
//    }
//}