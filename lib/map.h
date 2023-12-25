/**
 * \file map.h
 * \brief Un header file inclus la structure de map et les operations sur le map
 * \author Xinyi LIANG
 *
 * Le fichier map.h inclus la structure de map qui a un champ de 2D tableau avec le type enum CaseType pour représente le map\n
 * Il inclut aussi deux fonctions par rapport le map\n
 * Pour initialise le map à partir d'un fichier et pour display le map\n
 */


#ifndef MAP_H
#define MAP_H

#include "base.h"
#include "player.h"

/**
 * \brief Une énumération pour définir les entités de map
 */
typedef enum Characters{
	WALL = '#',
	BOX = 'x',
    PLAYER = 'p',
	GOAL = 'o',
	ETOILE = '*',
	NONE = ' '
} Characters;

/**
 * \brief Structure map
 *
 * Cette structure est destinée à définir un map, comprend tous les attributs nécessaires.\n
 */
typedef struct map {
	enum Characters** grid; //!< Tableau contenant les entités présents dans le jeu
	int nb_col; //!< Nombre de colonne de game_grid
	int nb_lgn; //!< Nomber de ligne de game_grid
	Player player;
} StrMap, *Map;


/**
 * \brief Initialise le map à partir d'un fichier
 * \param [in] file_path le path du fichier
 * \param [in] level valeur int pour determiner le niveau du map
 * \return un pointeur sur la structure map
 */
Map initMap(const char* file_path, int level);



/**
 * \brief affiche le map 
 * \param [in] map le pointeur sur la structure de map
 * \return Pas de valeur retourne
 */
void affiche_map(Map map);



#endif