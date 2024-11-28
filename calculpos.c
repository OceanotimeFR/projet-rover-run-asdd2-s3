#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
void Calculpos(t_node* arbre, int height, int* L[5], int drone_x, int drone_y, int map[map_size][map_size]) {
    int total_cost = 0;
    int current_x = drone_x;
    int current_y = drone_y;
    int angle=0;
    for (int i = 0; i < height; i++) {
        int move = *L[i];

        int next_x = current_x;
        int next_y = current_y;
        // partie ou en gros, tout les mouvement par rapport aux 7 donnés sont mises.
        if (move == 0 && angle==0){
            next_x +=1
        } else if (move == 1 && angle==0) {
            next_x += 2;
        } else if (move == 2 && angle==0)) {
            next_x += 3;
        } else if (move == 3 && angle==0) {
            next_x -=1 ;
        } else if (move == 4 &&angle==0) {
            angle=90
        } else if (move == 5 &&angle==0) {
            angle=270
        } else if (move ==6 &&angle==0) {
            angle=180
        }else if (move == 0 && angle==90){
            next_y -=1
        } else if (move == 1 && angle==90) {
            next_y -= 2;
        } else if (move == 2 && angle==90)) {
            next_y -= 3;
        } else if (move == 3 && angle==90) {
            next_y +=1 ;
        } else if (move == 4 &&angle==90) {
            angle=180
        } else if (move == 5 &&angle==90) {
            angle=0
        } else if (move ==6 &&angle==90) {
            angle=270
        }else if (move == 0 && angle==180){
            next_x -=1
        } else if (move == 1 && angle==180) {
            next_x -= 2;
        } else if (move == 2 && angle==180)) {
            next_x -= 3;
        } else if (move == 3 && angle==180) {
            next_x +=1 ;
        } else if (move == 4 &&angle==180) {
            angle=270
        } else if (move == 5 &&angle==180) {
            angle=90
        } else if (move ==6 &&angle==180) {
            angle=0
        }else if (move == 0 && angle==90){
            next_y =1
        } else if (move == 1 && angle==90) {
            next_y = 2;
        } else if (move == 2 && angle==90)) {
            next_y = 3;
        } else if (move == 3 && angle==90) {
            next_y -=1 ;
        } else if (move == 4 &&angle==90) {
            angle=360
        } else if (move == 5 &&angle==90) {
            angle=180
        } else if (move ==6 &&angle==90) {
            angle=90
        //si hors de la map, quite automatiquement
        if (next_x < 0 || next_y < 0 || next_x >= map_size || next_y >= map_size) {
            arbre->cost = -1;
            return;
        }

        int current_cost = map[next_x][next_y];
        //partie verif
        if (current_cost == 0) {
            arbre->cost = 0;
            return;
        }
        if (current_cost==100000){
            arbre->cost = -1;
            return;
        }
        if (current_cost=='10k+'){
            arbre->cost = -1;
            return;
        }

        total_cost += current_cost;

        current_x = next_x;
        current_y = next_y;
    }

    arbre->cost = total_cost;
}
