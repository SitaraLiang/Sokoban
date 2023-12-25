#include "../lib/map.h"

int skip_line(FILE *fp)
{
    int c;

    while (c = fgetc(fp), c != '\n' && c != EOF);

    return c;
}

Map initMap(const char* file_path, int level) {
    int nb_col, nb_lgn, pos_x, pos_y; 
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return NULL;
    };
    int current_line = 1;
    int items_read = fscanf(file, "%d %d %d %d", &nb_col, &nb_lgn, &pos_x, &pos_y);
    if (level == SECOND_LEVEL) {
       for (int i = 0; i <= nb_lgn; i++) {
            skip_line(file);
            current_line++;
       }
       items_read = fscanf(file, "%d %d %d %d", &nb_col, &nb_lgn, &pos_x, &pos_y);
       current_line++;
    } 
    if (items_read != 4) {
        printf("Error: Failed to read all items.\n");
        exit(-1);
    }

    Map map = (Map)malloc(sizeof(StrMap));
    map->nb_col = nb_col;
    map->nb_lgn = nb_lgn;
    map->grid = (Characters**)malloc((nb_lgn)*sizeof(Characters*));
    for (int i = 0; i < nb_lgn; i++) {
        map->grid[i] = (Characters*)malloc((nb_col)*sizeof(Characters));
    }
    int end_line = current_line + nb_lgn;
    int col;
    int lgn = 0;
    char line[100];
    fgets(line, 100, file);
    while(current_line < end_line) {
        col = 0;
        fgets(line, 100, file);
        while(col < nb_col) {
            map->grid[lgn][col] = line[col];
            col++;
        }
        lgn++;
        current_line++;
    }
    Player p;
    p.posX = pos_x;
    p.posY = pos_y;
    map->player = p;

    fclose(file);
    return map;

}

void display_map(Map map) {
    int cols = 0;
    int rows = 0;
    tc_get_cols_rows(&cols, &rows);
    int i;
    for (i = 0; i < map->nb_lgn; i++) {
        tc_move_cursor((int)(cols / 2 - map->nb_col / 2), (int)rows / 3+i);
        for (int j = 0; j < map->nb_col; j++) {
            if (map->grid[i][j] == CLOSED_GOAL) {
                printf("%s%c%s", TC_RED, BOX, TC_NRM);
            } else if (i == map->player.posY && j == map->player.posX) {
                printf("%s%c%s", TC_GRN, PLAYER, TC_NRM);
            } else if (map->grid[i][j] == OPEN_GOAL) {
                printf("%s%c%s", TC_YEL, OPEN_GOAL, TC_NRM);
            } else if (map->grid[i][j] == BOX) {
                printf("%s%c%s", TC_MAG, BOX, TC_NRM);
            } else if (map->grid[i][j] == WALL) {
                printf("%s%c%s", TC_BLU, WALL, TC_NRM);
            }
            
            else {
                printf("%c", map->grid[i][j]);
            }

        }
           
        printf("\n");

    }
    tc_move_cursor((int)(cols / 2 -  6), (int)rows / 3 + i+1);
}

