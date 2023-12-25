/**
 * \file operation.h
 * \brief Header file contenant les opérations pour faire bouger le joueur et pour vérifier la position des boîtes
 * \author Leaticia BIBI
 *
 * Le fichier operation.h contient deux fonctions : movePlayer et checkBox\n
 * Pour déplacer le joueur et vérifier la position des boîtes respectivement\n
 */


#ifndef OPERATION_H
#define OPERATION_H

#include "map.h"

/**
 * \brief Move the player.\n This function will update the player's position according to the direction in parameters.\n
 * \param [in] map A pointer to the map for the current game session
 * \param [in] d the direction with type enum in which the player will be moved
 * \return No return value
 */
void movePlayer(Map map, Direction d);

/**
 * \brief Auxiliary function. Moving the box.
 * \param [in] map A pointer to the map for the current game session
 * \param [in] d the direction with type enum in which the box will be pushed
 * \return Boolean value: if the player successfully pushes the box then true otherwise false.
 */
Bool moveBox(Map map, Direction d, int x, int y);

/**
 * \brief Auxiliary function. Check if the player or box hit the wall on the next move.
 * \param [in] map A pointer to the map for the current game session
 * \param [in] d the direction with type enum in which the player or box will be moved
 * \return Boolean value: if the player or box hit the wall on the next move then true otherwise false.
 */
Bool hitWall(Map map, Direction d, int x, int y);

/**
 * \brief Auxiliary function. Move the closed-goal.
 * \param [in] map A pointer to the map for the current game session
 * \param [in] d the direction with type enum in which the the closed-goal will be moved
 * \return Boolean value: if the closed goal is successfully moved then true otherwise false.
 */
Bool moveEtoile(Map map, Direction d, int x, int y);

/**
 * \brief Check the completion of the goal in the map
 * \param [in] map A pointer to the map for the current game session
 * \return Boolean value: if all boxes are in the goal then True otherwise False
 */
Bool CheckForFullGoal(Map m);

/**
 * \brief Show greeting message at the end of game
 * \param [in] msg string of characters.
 * \return No return value
 */
void endGame(char* msg);

#endif
