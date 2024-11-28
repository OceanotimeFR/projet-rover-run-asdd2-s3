#include "tree.c"
#include <time.h>
#include <limits.h>

int main(){


    int global_tab[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int height = 0;
    t_tree tree = createEmptyTree();
    tree.root->value = 0;
    tree.root->depth = 0;

    treefilled(tree.root, global_tab, 0);


    printTree(tree.root, 0);



    return 0;
}