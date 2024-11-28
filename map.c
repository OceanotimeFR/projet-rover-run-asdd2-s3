#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"


int base_x = -1, base_y = -1;
int drone_x = -1, drone_y = -1; 

void map_matrix(int map[map_size][map_size]) {
    printf("Carte des terrains :\n");

    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            int biome = rand() % 4;
            int biome_list[4] = {plaine, reg, erg, crevasse};
            map[i][j] = biome_list[biome];
        }
    }

    base_x = rand() % map_size;
    base_y = rand() % map_size;
    map[base_x][base_y] = BASE;

    do {
        drone_x = rand() % map_size;
        drone_y = rand() % map_size;
    } while (drone_x == base_x && drone_y == base_y);
    map[drone_x][drone_y] = DRONE;

    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            printf("+-----");
        }
        printf("+\n");
        for (int j = 0; j < map_size; j++) {
            printf("|");
            if (i == drone_x && j == drone_y) {
                printf("  D  ");
            } else if (map[i][j] == plaine) {
                printf("  P  ");
            } else if (map[i][j] == reg) {
                printf("  R  ");
            } else if (map[i][j] == erg) {
                printf("  E  ");
            } else if (map[i][j] == crevasse) {
                printf("  C  ");
            } else if (map[i][j] == BASE) {
                printf("  0  ");
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < map_size; j++) {
        printf("+-----");
    }
    printf("+\n");

    printf("Position de la base : (%d, %d)\n", base_x, base_y);
    printf("Position du drone : (%d, %d)\n", drone_x, drone_y);
}

void calculate_costs_and_display(int map[map_size][map_size]) {
    int costs[map_size][map_size];

    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            costs[i][j] = INT_MAX;
        }
    }

    costs[base_x][base_y] = 0;

    int queue[map_size * map_size][2];
    int front = 0, rear = 0;

    queue[rear][0] = base_x;
    queue[rear][1] = base_y;
    rear++;

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;

        for (int d = 0; d < 4; d++) {
            int nx = x + directions[d][0];
            int ny = y + directions[d][1];

            if (nx >= 0 && ny >= 0 && nx < map_size && ny < map_size && map[nx][ny] != crevasse) {
                int new_cost = costs[x][y] + ((nx == drone_x && ny == drone_y) ? 1 : map[nx][ny]);
                if (new_cost < costs[nx][ny]) {
                    costs[nx][ny] = new_cost;
                    queue[rear][0] = nx;
                    queue[rear][1] = ny;
                    rear++;
                }
            }
        }
    }

    printf("\nCarte des couts :\n");
    for (int i = 0; i < map_size; i++) {
        for (int j = 0; j < map_size; j++) {
            printf("+-------");
        }
        printf("+\n");
        for (int j = 0; j < map_size; j++) {
            printf("|");
            if (i == drone_x && j == drone_y) {
                printf("   D   ");
            } else if (map[i][j] == crevasse) {
                printf(" 10000 ");
            } else if (costs[i][j] == INT_MAX) {
                printf(" 10k+  ");
            } else if (costs[i][j] < 10) {
                printf("   %d   ", costs[i][j]);
            } else {
                printf("   %d  ", costs[i][j]);
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < map_size; j++) {
        printf("+-------");
    }
    printf("+\n");
}
