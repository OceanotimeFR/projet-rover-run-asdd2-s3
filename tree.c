#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "liste.h"



// Fonction pour créer un arbre vide
t_tree createEmptyTree() {
    t_tree tree;
    tree.root = (p_node) malloc(sizeof(t_node));


    return tree;
}

void treefilled(p_node arbre, int T[9], int height) {

    arbre->depth = height;

    // Allouer les 9 enfants pour ce nœud
    arbre->table = (t_node**) malloc((9-height) * sizeof(t_node*));
    if (height >4) {
        for (int i = 0; i < (9-height); i++) {
            arbre->table[i] = NULL;
        }
        return;
    }

    // Initialiser le nœud courant

    arbre->depth = height;

    // Allouer les 9 enfants pour ce nœud





    // Remplir les enfants récursivement
    for (int i = 0; i < (9-height); i++) {
        arbre->table[i] = (p_node) malloc(sizeof(t_node));


        // Modifier la liste pour chaque enfant sans utiliser memcpy

        allouerenfants(i, height, arbre, T);
        // Remplir récursivement chaque enfant

    }
}

void allouerenfants(int i, int height, t_node* arbre, int* L) {
    if (height >4) {
        return;
    }
    int* L1= copyList(L,i);

    arbre->table[i]->value =L[i];


    treefilled(arbre->table[i], L1, height + 1);
}
int* newlist(int i, int j, int L[9]) {
    // Cette fonction inverse deux éléments dans la liste L
    int temp = L[i];
    L[i] = L[8 - j];
    L[8 - j] = temp;
    return L;}
int* copyList(int L[9] ,int i) {
    int* newL = (int*) malloc((9)* sizeof(int));
    int p=0;
    for (int j =0;j<(8);j++) {
        if(j==i){
            p++;
        }
        newL[j] = L[j+p];
    }
    return newL;
}

// Fonction pour afficher l'arbre
void printTree(p_node node, int level) {
    if (node == NULL) {
        return; // Si le nœud est NULL, on arrête la récursion
    }

    // Indentation pour représenter la profondeur
    for (int i = 0; i < level; i++) {
        printf("    "); // Quatre espaces pour chaque niveau
    }

    // Afficher la valeur et la profondeur du nœud
    printf("Node (Value: %d, Depth: %d)\n", node->value, node->depth);

    // Afficher récursivement les 9 enfants
    for (int i = 0; i < (9-node->depth); i++) {
        printTree(node->table[i], level + 1);
    }
}