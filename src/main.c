#include "../lib/operation.h"


void tc_get_cols_rows(int *cols, int *rows){
	struct winsize size;
	ioctl(1, TIOCGWINSZ, &size);
	*cols = size.ws_col;
	*rows = size.ws_row;
}

void tc_echo_off(){
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(1, TCSANOW, &term);
}

void tc_echo_on(){
	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ECHO;
	tcsetattr(1, TCSANOW, &term);
}

/*
void resize_window() {
    clear_screen();
    int cols = 0;
    int rows = 0;
    tc_get_cols_rows(&cols, &rows);
    char welcome[] = "WELCOME TO SOKOBAN GAME!";
    tc_move_cursor((int)((cols - strlen(welcome)) / 2), (int)rows / 4);
    printf("%s%s%s\n", WHT_ON_RED, welcome, TC_NRM);
}
*/


int main(){
    //signal(SIGWINCH, &resize_window);
    clear_screen();
    Bool quit = false;
    int current_level = FIRST_LEVEL;
    char input;
    Map map = initMap("level.txt", current_level);
    int cols = 0;
    int rows = 0;                                                           
    tc_get_cols_rows(&cols, &rows);
    char msg[100] = "WELCOME TO SOKOBAN GAME!";
    tc_move_cursor((int)((cols - strlen(msg)) / 2), (int)rows / 4);
    printf("%s%s%s%s%s\n", BOLD, WHT_ON_RED, msg, TC_NRM, NORMAL);
    affiche_map(map);
    


    while(!quit) {  
        initscr();   
        noecho();
        cbreak();
        timeout(-1);
        input = getchar();
        endwin();   
        clear_screen();
        if (current_level == FIRST_LEVEL) {
            strcpy(msg, "FIRST LEVEL");
        }
        tc_move_cursor((int)((cols - strlen(msg)) / 2), (int)rows / 4);
        printf("%s%s%s%s%s\n", BOLD, WHT_ON_RED, msg, TC_NRM, NORMAL);
        affiche_map(map);

        switch(input){
            case UP:
                printf("Moving up\n");
                movePlayer(map, UP);
                endwin();
                break;
            case LEFT:
                printf("Moving left\n");
                movePlayer(map, LEFT);
                endwin();
                break;
            case DOWN:
                printf("Moving down\n");
                movePlayer(map, DOWN);
                endwin();
                break;
            case RIGHT:
                printf("Moving right\n");
                movePlayer(map, RIGHT);
                endwin();
                break;
            case 'q':
                quit = true;
                printf("Quit\n");
                endwin();
                break;
            case 'r':
                map = initMap("level.txt", current_level);
                affiche_map(map);
                printf("Redemarrer\n");
                endwin();
                break;
            default:
                endwin();
                break;
        }

       
        if (!quit && CheckForFullGoal(map)) {
            if (current_level == SECOND_LEVEL) {
                endGame("You win!");
                break;
            } else {  
                clear_screen();
                tc_move_cursor((int)((cols - strlen("You win! Move to next level [m], or quit [q]?")) / 2), (int)rows / 4);
                printf("%s%s%s%s%s\n", BOLD, WHT_ON_RED, "You win! Move to next level [m], or quit [q]?", TC_NRM, NORMAL);
                endwin();

                noecho();
                cbreak();
                input = getchar();

                if (input == 'm') {
                    clear_screen();
                    strcpy(msg, "SECOND LEVEL");
                    tc_move_cursor((int)((cols - strlen(msg)) / 2), (int)rows / 4);
                    printf("%s%s%s%s%s\n", BOLD, WHT_ON_RED, msg, TC_NRM, NORMAL);
                    current_level = SECOND_LEVEL;
                    map = initMap("level.txt", current_level);
                    affiche_map(map);
                    endwin();
                } else if (input == 'q') {
                    quit = true;
                    endwin();
                }
            }
        }
    }
    return 0;
}