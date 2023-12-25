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
 * \brief Déplace le joueur
 * \param [in] map la map dans laquelle le joueur sera déplacé
 * \param [in] d la direction dans laquelle le joueur sera déplacé
 * \return Pas de valeur retournée
 */
void movePlayer(Map map, Direction d);

Bool moveBox(Map map, Direction d, int x, int y);

Bool hitWall(Map map, Direction d, int x, int y);

Bool moveEtoile(Map map, Direction d, int x, int y);

/**
 * \brief Vérifie la position des boîtes
 * \param [in] map la map dans laquelle le joueur sera déplacé
 * \return Bool Si toutes les boîtes sont dans la bonne position alors Vrai sinon Faux
 */
Bool CheckForFullGoal(Map m);

/**
 * \brief Afficher le message au début de jeu ou à la fin 
 * \param [in] msg message est une chaine de caractères.
 * \return Pas de valeur de retour
 */
void endGame(char* msg);

#endif
