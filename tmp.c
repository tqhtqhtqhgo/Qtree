//
// Created by caaffrey on 2020/3/2.
//
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "qtree.h"
// make a node at given location (x,y) and level

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

    return;
}

// write out the tree to file 'quad.out'

void writeTree( Node *head ) {

    FILE *fp = fopen("quad.out","w");

    writeNode(fp,head);

    fclose(fp);

    return;
}

// recursively visit the leaf nodes

void writeNode( FILE *fp, Node *node ) {

    int i;

    if( node->child[0] == NULL )
        printOut( fp, node );
    else {
        for ( i=0; i<4; ++i ) {
            writeNode( fp, node->child[i] );
        }
    }
    return;
}

// write out the (x,y) corners of the node

void printOut( FILE *fp, Node *node ) {
    double x = node->xy[0];
    double y = node->xy[1];
    int level = node->level;
    double h = pow(2.0,-level);
    fprintf(fp, " %g %g\n",x,y);
    fprintf(fp, " %g %g\n",x+h,y);
    fprintf(fp, " %g %g\n",x+h,y+h);
    fprintf(fp, " %g %g\n",x,y+h);
    fprintf(fp, " %g %g\n\n",x,y);

    return;
}


