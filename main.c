#include "writeTree.h"
// main

int main( int argc, char **argv ) {

    Node *head;

    // make the head node
    head = makeNode( 0.0,0.0, 0 );

    // make a tree
    makeChildren(head);
    makeChildren(head->child[1]);
    makeChildren(head->child[2]);
    growTree(head);

    writeTree( head );
    return 0;
}

