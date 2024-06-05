/**
 * \file grid.h
 * \brief Contient enum caseType et la structure Grid ainsi que les prototypes de fonctions
 */

#ifndef GRID_HEADER
#define GRID_HEADER
#include "player.h"

/**
 * \enum CaseType
 * \brief Cette structure contient les informations
 * concernant la grille de jeux "Game_grid": 
 * wall   = # = mur,
 * box    = $ = boxe,
 * player = @ = joueur,
 * goal   = . = but,
 * none   =   = espace vide ou on peut se deplacer
 * Ajout d'un élément PLAYER_ON_A_GOAL, BOX_ON_GOAL qui indique si le 
 * personnage/une boîte est sur un objectif 
 */
enum CaseType
{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' ',
	PLAYER_ON_A_GOAL = 'a',
	BOX_ON_A_GOAL = 's'
};

/**
 * @struct Grid
 * @brief Cette structure contient les informations
 * concernant la grille du jeu et son contenu
 */
typedef struct Grid Grid;
struct Grid
{
	enum CaseType **game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number;		   ///< Nombre de colonne de game_grid
	int row_number;			   ///< Nomber de ligne de game_grid
	Player joueur;			   /// <Ajout d'un joueur
	int nbrCibles; 			  ///< Nombre de points cibles dans la grille
	int ciblesRecouvertes; ///< Nombre de points cibles recouverts
	int boxNumber;         /// <Compte le nombre de box a deplacer dans le jeu
};


	/////  PROTOTYPES DES FONCTIONS    
		

/**
 * \fn init_level(const char* file_path, Grid *maGrid)
 * \brief Fonction qui lit un fichier .txt et remplit la structure Grid avec les éléments présents dans le fichier
 * \param const char* file_path
 * \param Grid *maGrid Pointeur sur la structure Grid 
 */
struct Grid *init_level(const char *file_path, struct Grid *maGrid);

/** 
 * \fn display(Grid *pointeurNiveau)
 * \brief fonction qui permet d'afficher un niveau
 * \param Grid *pointeurNiveau
 */
void display(struct Grid *pointeurNiveau);
/**
 * \fn freeGrid(Grid *maGrid)
 * \brief fonction qui permet de libérer la mémoire utilisée par 
 * le tableau dans la structure Grid
 * \param Grid *maGrid
 */
void free_Grid(struct Grid *maGrid);

#endif
