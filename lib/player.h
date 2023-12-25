/**
 * \file player.h
 * \brief Header file incluant la structure player et un type enum direction 
 * \author TAYEBI Lyna 
 *
 * Ce fichier player.h inclus une structure player. \n
 * Ainsi qu'un enum pour decrire les directions que l'utilisateur va entrer. \n
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER


/**
 * \brief Structure player
 * 
 * Cette structure contient la position du joueur, soit player dans la map. \n
*/

typedef struct player{
    int posX; ///< la colonne dans laquelle se trouvera le joueur
    int posY; ///< la ligne ou se trouvera le joueur 
} Player;



/**
 * \enum Direction
 * \brief Type Enum direction
 * 
 * Enumération pour la direction dans la map
*/

typedef enum Direction{
	UP = 'w', ///< w: haut
	LEFT = 'a', ///< a: gauche
	DOWN = 's', ///< s: bas
	RIGHT = 'd' ///< d: droite
} Direction;

#endif
