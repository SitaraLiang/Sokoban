/**
 * \file player.h
 * \brief Header file including the player structure and an enum type
 *
 * This file includes a basic structure of player, and an enum representing the direction\n
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER


/**
 * \brief Structure of player
 * 
 * Cette structure contient la position du joueur, soit player dans la map. \n
*/

typedef struct player{
    int posX; ///< la colonne dans laquelle se trouvera le joueur
    int posY; ///< la ligne ou se trouvera le joueur 
} Player;



/**
 * \enum Direction
 * \brief Type enum of direction
 * 
 * Using the type enum in C for representing the direction player can move in the game. 
*/

typedef enum Direction{
	UP = 'w', ///< w: up
	LEFT = 'a', ///< a: left
	DOWN = 's', ///< s: down
	RIGHT = 'd' ///< d: right
} Direction;

#endif
