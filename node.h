#ifndef UNTITLED12_NODE_H
#define UNTITLED12_NODE_H


typedef struct Node {
    int val;
} Node;



typedef struct s_node
{
    int value;
    struct s_node** table ;
    int depth;
}s_node;

typedef struct s_node t_node,*p_node;

t_node* createNode(int val);
t_node *insertNode(t_node *root, int value);
Node* createNodeBr(int val);
void printNode(Node* node);


#endif //UNTITLED12_NODE_H
