#include "math.h"
#include "nodeValue.h"
#include "stdlib.h"
// Evaluate function at centre of quadtree node

double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function

double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(y-time)) - 1.0 ) ;
}

int nodeFlag(Node *root){
    root->flag=0;
    for (int i = 0; i <4 ; ++i) {
        if (root->child[i]!=NULL){
            return root->flag;
        }
    }
    double NodeValueRESULT=nodeValue(root,0);
    if (NodeValueRESULT>0.5){
        root->flag=1;
    }
    else if(NodeValueRESULT<-0.5){
        root->flag=-1;
    }
    return root->flag;
}

int generateTree(Node *node){
    if (node->child[0]==NULL && node->child[1]==NULL && node->child[2]==NULL && node->child[3]==NULL){
        if (nodeFlag(node)==1){
            makeChildren(node);
        }
    }
    else if(node->child[0]!=NULL || node->child[1]!=NULL || node->child[2]!=NULL || node->child[3]!=NULL){
         if(node->child[0]!=NULL && node->child[1]!=NULL && node->child[2]!=NULL && node->child[3]!=NULL){
            if(nodeFlag(node->child[0])==-1 && nodeFlag(node->child[1])==-1 && nodeFlag(node->child[2])==-1 && nodeFlag(node->child[3])==-1){
                removeChild(node);
            }
            else{
                for (int i = 0; i < 4; ++i) {
                    generateTree(node->child[i]);
                }
            }
        }
         else{
             for (int i = 0; i <4 ; ++i) {
                 if (node->child[i]!=NULL){
                     generateTree(node->child[i]);
                 }
             }
         }
    }
    return 0;
}