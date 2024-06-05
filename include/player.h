/**
 * \file player.h
 * \brief Contient enum Direction , les prototypes de fonctions et la structure Player
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include <stdio.h>
#include "grid.h"

/**
 * \enum Direction
 * \brief Cette structure contient les informations
 * concernant le déplacement du joueur "dans notre cas '@"
 * k: haut, h: gauche, l: droite, j: bas
 */
/**
 * \typedef enum Direction Direction
 */
typedef enum Direction Direction;
enum Direction
{
    Top = 'k',          // Haut
    Left = 'h',         // Gauche
    Right = 'l',        // Droite
    Bottom = 'j'        // Bas
};

/**
 * @struct Player
 * @brief Cette structure contient les differentes positions du joueur dans le repere
 */
typedef struct Player
{
    int x; // Deplacement horizontale
    int y; // Deplacement Vertical
} Player;

/**
 * \fn move_player(struct Grid *g, Direction d)
 * \brief fonction qui permet de déplacer le personnage dans la
 * direction demandée
 * \param struct Grid *maGrid
 * \param Direction direction
 */

struct Grid;
void move_player(enum Direction direction, struct Grid *maGrid);

/**
 * \fn int toutesLesCiblesRecouvertes(Grid* maGrid)
 * \brief Fonction qui retourne si toutes les cibles 
 * sont recouvertes
 * \param Grid* maGrid
 */
//typedef int bool;
int toutesLesCiblesRecouvertes(struct Grid *maGrid);

#endif