#include "liste.h"
#include <stdlib.h>
#include <stdio.h>

void newliste(int liste[], int i, int j) {
    // Vérification de la validité des indices
    if (i >= 0 && i < 9 && j >= 0 && j < 9) {
        int temp = liste[i];
        liste[i] = liste[j];
        liste[j] = temp;

    } else {
        printf("Erreur : Indices hors limites.\n");
    }
    printf("\n");
}


