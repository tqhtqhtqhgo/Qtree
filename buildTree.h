#include "treeStructure.h"


Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void destroyTree(Node *head);
int growTree(Node* InRoot);
void removeChild(Node *root);
