#include <bits/types/FILE.h>

// tree data structure
struct qnode {
    int level;
    double xy[2];
    struct qnode *child[4];
};
typedef struct qnode Node;

// function definitions

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );