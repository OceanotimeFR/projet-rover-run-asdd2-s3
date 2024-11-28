#ifndef UNTITLED12_TREE_H
#define UNTITLED12_TREE_H
#include "node.h"

typedef struct s_tree
{
    p_node root;

} t_tree;


t_tree createEmptyTree();
int* copyList(int L[9], int i);
void treefilled(p_node arbre, int T[9], int height);

void allouerenfants(int i, int height,t_node* arbre,int T[9]);

int* newlist( int i, int j,int L[9]);
void printTree(p_node node, int level);


#endif //UNTITLED12_TREE_H

