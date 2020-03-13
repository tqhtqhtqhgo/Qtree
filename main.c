#include "nodeValue.h"
#include "stdio.h"
// main

int main( int argc, char **argv ) {

    Node *head;

    // make the head node
    head = makeNode( 0.0,0.0, 0 );
    growTree(head);
    growTree(head);
    makeChildren(head->child[1]->child[1]);
    double n=nodeValue(head->child[1]->child[1],0);
    printf("%f",n);
    removeChild(head->child[1]->child[1]);
    writeTree(head);

    return 0;
}

