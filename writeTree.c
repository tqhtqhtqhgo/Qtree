//
// Created by caaffrey on 2020/3/2.
//
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "writeTree.h"

// write out the tree to file 'quad.out'

void writeTree( Node *head ) {
    FILE *fp = fopen("quad.out","w");
    writeNode(fp,head);
    fclose(fp);
    destroyTree(head);
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

}

void destroyTree(Node *head){
    if(head!=NULL){
        destroyTree(head->child[0]);
        destroyTree(head->child[1]);
        destroyTree(head->child[2]);
        destroyTree(head->child[3]);
        free(head);
    }
}




