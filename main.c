#include "tree.h"
#include "liste.h"
int main(){

    int global_tab[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int height = 0;

    t_tree t;
    treefilled(t.root, global_tab, height);

    return 0;
}