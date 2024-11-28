#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


// Fonction pour créer un arbre vide
t_tree createEmptyTree() {
    t_tree tree;
    tree.root = (p_node) malloc(sizeof(t_node));


    return tree;
}

void treefilled(p_node arbre, int T[9], int height) {

    arbre->depth = height;
    arbre->table = (t_node**) malloc((9-height) * sizeof(t_node*));             //alloue l'espace mémoire necessaire au nombre d'enfants de ce noeud (par rapport donc a sa profondeur)
    //arbre->parcours=(int*) malloc((9)* sizeof(int));
    if (height >4) {
        for (int i = 0; i < (9-height); i++) {
            arbre->table[i] = NULL;
        }
        return;
    }
    arbre->depth = height;
    for (int i = 0; i < (9-height); i++) {
        arbre->table[i] = (p_node) malloc(sizeof(t_node));
        allouerenfants(i, height, arbre, T);                    // Remplie chaque enfant en utilisant la fonction treefilled (donc maniere recursive)
    }
}

void allouerenfants(int i, int height, t_node* arbre, int* L) {
    if (height >4) {
        return;                     //profondeur max atteinte, inutil de continuer
    }
    int* L1= copyList(L,i);             //afin d'avoir la liste des valuers mise a jour pour ne pas reutiliser plusieurs fois la meme

    arbre->table[i]->value =L[i];
    //arbre->table[i]->parcours=listmouv(L,i,height);

    treefilled(arbre->table[i], L1, height + 1);
}
int* listmouv(int L[9],int i,int height){
    int* newL = (int*) malloc((5)* sizeof(int));
    newL[height-1]=L[i];
    return newL;
}

int* copyList(int L[9] ,int i) {
    int* newL = (int*) malloc((9)* sizeof(int));
    int p=0;
    for (int j =0;j<(8);j++) {
        if(j==i){                           //detection de la valeur a la position i qui n'est plus a utiliser
            p++;                            //incrémente pour pouvoir sauter la valeur trouvée
        }
        newL[j] = L[j+p];                   //la liste fera donc au total j-1 élément
    }
    return newL;
}

// Fonction pour afficher l'arbre
void printTree(p_node node, int level) {
    if (node == NULL) {
        return; // Si le nœud est NULL, on arrête la récursion
    }
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