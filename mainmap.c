#include <stdlib.h>
#include <time.h>
#include "map.h"

int main() {
    srand(time(NULL));
    int map[map_size][map_size] = {0};

    map_matrix(map);
    calculate_costs_and_display(map);

    return 0;
}
