#include "../lib/operation.h"

/*
    1.move player
    2.change position of player, check if reach the wall then do not change
    3.check if moving direction has a box
    4.if there is, move the box(change the position of box)
        - check if box reach the wall, dont change
    5.check if box hit the goal, if it is, replace "o" by box
    
*/


void movePlayer(Map map, Direction d){
    int x = map->player.posX;
    int y = map->player.posY;
    switch(d) {
        case UP:
            y--;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWN:
            y++;
            break;
    }

    if (map->grid[y][x] == BOX) {
        if (moveBox(map, d, x, y)) {
            if (map->grid[map->player.posY][map->player.posX] != GOAL) {
                map->grid[map->player.posY][map->player.posX] = NONE;
            }
            map->grid[y][x] = NONE;
            map->player.posX = x;
            map->player.posY = y;
        }
    } else if (map->grid[y][x] == ETOILE) {
        if (moveEtoile(map, d, x, y)) {
            map->grid[y][x] = GOAL;
            map->player.posX = x;
            map->player.posY = y;
        }
    }
    else if (!hitWall(map, d, x, y)) {
        //map->grid[map->player.posY][map->player.posX] = NONE;
        //map->grid[y][x] = PLAYER;
        map->player.posX = x;
        map->player.posY = y;
    }
    affiche_map(map);
    
}

Bool moveEtoile(Map map, Direction d, int x, int y) {
    switch(d) {
        case UP:
            y--;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWN:
            y++;
            break;
    }
    if (!hitWall(map, d, x, y)) {
        map->grid[y][x] = BOX;
        return true;
    }
    return false;
}



Bool moveBox(Map map, Direction d, int x, int y) {
    switch(d) {
        case UP:
            y--;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case DOWN:
            y++;
            break;
    }
    if (!hitWall(map, d, x, y)) {
        if (map->grid[y][x] == GOAL) {
            map->grid[y][x] = ETOILE;
        } else {
            map->grid[y][x] = BOX;
        }
        return true;
    }
    return false;
}



Bool hitWall(Map map, Direction d, int x, int y) {
    if (map->grid[y][x] == WALL) {
        return true;
    }
    return false;
}




Bool CheckForFullGoal(Map map){
    for (int i = 0; i < map->nb_lgn; i++) {
        for (int j = 0; j < map->nb_col; j++) {
            if (map->grid[i][j] == GOAL) {
                return false;
            }
        }
    }
    return true;
}

void endGame(char* msg) {
    clear_screen();
    int cols = 0;
    int rows = 0;
    tc_get_cols_rows(&cols, &rows);
    tc_move_cursor((int)((cols - strlen(msg)) / 2), (int)rows / 2);
    printf("%s%s%s%s%s\n", BOLD, WHT_ON_RED, msg, TC_NRM, NORMAL);
}