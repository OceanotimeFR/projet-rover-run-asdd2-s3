#ifndef MAP_H
#define MAP_H

#include <limits.h> // à conserver, juste pr INT_MAX

#define map_size 5
#define plaine 1
#define reg 2
#define erg 4
#define crevasse 10000
#define BASE 0
#define DRONE 1 


extern int base_x, base_y; //posB
extern int drone_x, drone_y; // PosD

void map_matrix(int map[map_size][map_size]);
void calculate_costs_and_display(int map[map_size][map_size]);

#endif 
