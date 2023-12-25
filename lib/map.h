/**
 * \file map.h
 * \brief Header file includes the map structure and operations on the map
 *
 * This file includes the map structure which has a 2D array field with enum type CaseType to represent the map\n
 * It also includes two functions related to the map, in order to initialize the map from a file and to display the map\n
 */ 


#ifndef MAP_H
#define MAP_H

#include "base.h"
#include "player.h"

/**
 * \brief An enumeration to define map entities
 */
typedef enum Characters{
	WALL = '#',
	BOX = 'x', 
    PLAYER = 'p',
	OPEN_GOAL = 'o',
	CLOSED_GOAL = '*',
	NONE = ' '
} Characters;

/**
 * \brief Structure of map
 *
 * This structure is intended to define a map, includes all the necessary attributes.\n
 */
typedef struct map {
	enum Characters** grid; //!< Table 2D containing the entities present in the game
	int nb_col; //!< Number of game_grid columns
	int nb_lgn; //!< Number of game_grid rows
	Player player; //!< Object of the structure of player
} StrMap, *Map;


/**
 * \brief Initialize the map from a file
 * \param [in] file_path the path of the file
 * \param [in] level integer value to determine the map level
 * \return a pointer to the map structure
 */
Map initMap(const char* file_path, int level);



/**
 * \brief Display the map on the terminal 
 * \param [in] map the pointer to the map structure
 * \return No return value
 */
void display_map(Map map);



#endif