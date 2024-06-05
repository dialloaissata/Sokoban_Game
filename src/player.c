/**
 * \file player.c
 * \brief fichier contenant la fonction move_player et toutesLesCiblesRecouvertes
 */
#include <stdlib.h>
#include <stdio.h>
#include "grid.h"
#include "player.h"

/**
 * \fn move_player(enum Direction direction, struct Grid *maGrid)
 * \brief Fonction qui permet de deplacer le joueur dans la grille de jeu 
 *
 * \param direction variable de type enum pour stocker la position du joueur
 * \param maGrid pointeur sur la structure Grid
 */

void move_player(enum Direction direction, struct Grid *maGrid)
{
	//nextPosJoueur : case devant le personnage
	int nextPosJoueurX = maGrid->joueur.x;  
	int nextPosJoueurY = maGrid->joueur.y;
	// nextNext : case du personnage + 2
	int nextNextX = maGrid->joueur.x;  
	int nextNextY = maGrid->joueur.y;
	
	switch (direction)
	{
	case Top:
	{
		nextPosJoueurX --;
		nextNextX -=2;
		break;
	}

	case Bottom:
	{
		nextPosJoueurX ++;
		nextNextX +=2;
		break;
	}
	case Right:
	{
		nextPosJoueurY ++;
		nextNextY +=2;
		break;
	}

	case Left:
	{
		nextPosJoueurY --;
		nextNextY -=2;
		break;
	}
	default:
		printf("\nErreur : veuillez choisir une direction parmi h : gauche, j : bas, k : haut, l : droite\n");
		break;
	}

	//s'il n'y a rien devant le joueur et qu'il ne se trouve pas sur un objectif
	if((maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] == ' ') && (maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] == '@'))
	{
		//on attribut les nouvelles coordonnées du joueur
		maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] = '@';
		//on efface son ancienne position
		maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] = ' ';
		//on modifie la position dans la structure
		maGrid->joueur.x = nextPosJoueurX;
		maGrid->joueur.y = nextPosJoueurY;
	}

	//s'il y a un objectif devant le joueur et qu'il ne se trouve pas sur un objectif
	if ((maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] == '.') && (maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] == '@'))
	{	
		//on attribut les nouvelles coordonnées du joueur
		maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] = PLAYER_ON_A_GOAL;
		//on efface son ancienne position
		maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] = ' ';
		//on modifie la position dans la structure
		maGrid->joueur.x = nextPosJoueurX;
		maGrid->joueur.y = nextPosJoueurY;
	}

	//s'il n'y a rien devant le joueur et qu'il se trouve pas sur un objectif
	if ((maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] == ' ') && (maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] == PLAYER_ON_A_GOAL))
	{
		//on attribut les nouvelles coordonnées du joueur
		maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] = '@';
		//on remet l'objectif sur lequel le personnage se trouvait
		maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] = '.';
		//on modifie la position dans la structure
		maGrid->joueur.x = nextPosJoueurX;
		maGrid->joueur.y = nextPosJoueurY;
	}

	//s'il y a un objectif devant le joueur et qu'il se trouve pas sur un objectif
	if ((maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] == '.') && (maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] == PLAYER_ON_A_GOAL))
	{	
		//on attribut les nouvelles coordonnées du joueur
		maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] = PLAYER_ON_A_GOAL;
		//on remet l'objectif sur lequel se trouvait le personnage
		maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] = '.';
		//on modifie la position dans la structure
		maGrid->joueur.x = nextPosJoueurX;
		maGrid->joueur.y = nextPosJoueurY;
	}
	
	//s'il y a une boîte devant le joueur et qu'il n'y a rien devant la boîte
	if ((maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] == '$') && (maGrid->game_grid[nextNextX][nextNextY] == ' '))
	{
		//on avance la boîte
		maGrid->game_grid[nextNextX][nextNextY] = '$'; 
		//on enlève la boîte de son ancienne position, à la place on met le personnage
		maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] = '@';
		//si le personnage se trouvait sur un objectif, on le remet
		if (maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] == PLAYER_ON_A_GOAL)
		{
			//on remet l'objectif sur lequel se trouvait le personnage
			maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] = '.';
		}
		else
		{
			//on supprime son ancienne positon
			maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] = ' ';
		}
		maGrid->joueur.x = nextPosJoueurX;
		maGrid->joueur.y = nextPosJoueurY;
	}

	//s'il y a une boîte devant le joueur et qu'il y a un objectif devant la boîte
	if ((maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] == BOX) && (maGrid->game_grid[nextNextX][nextNextY] == '.'))
	{
		maGrid->game_grid[nextNextX][nextNextY] = BOX_ON_A_GOAL; //on avance la boîte
		//on enlève la boîte de son ancienne position, à la place on met le personnage
		maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] = '@';
		//on supprime son ancienne positon
		maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] = ' ';
		//si le personnage se trouvait sur un objectif, on le remet
		if (maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] == PLAYER_ON_A_GOAL)
			maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] = '.';
		maGrid->ciblesRecouvertes++; //incrémentation du compteur de cibles recouvertes
		//on modifie la position dans la structure
		maGrid->joueur.x = nextPosJoueurX;
		maGrid->joueur.y = nextPosJoueurY;
	}
	
	//s'il y a une boîte sur un objectif devant le personnage et qu'il n'y a rien devant
	if ((maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] == BOX_ON_A_GOAL) && (maGrid->game_grid[nextNextX][nextNextY] == ' '))
	{
		maGrid->game_grid[nextNextX][nextNextY] = '$';
		maGrid->game_grid[nextPosJoueurX][nextPosJoueurY] = PLAYER_ON_A_GOAL;
		maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] = ' ';
		//si le personnage se trouvait sur un objectif
		if (maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] == PLAYER_ON_A_GOAL)
			maGrid->game_grid[maGrid->joueur.x][maGrid->joueur.y] = '.';
		maGrid->ciblesRecouvertes--; // On decremente le nombre de cibles recouvert
		//on modifie la position dans la structure
		maGrid->joueur.x = nextPosJoueurX;
		maGrid->joueur.y = nextPosJoueurY;
	}
}

/**
 * \fn toutesLesCiblesRecouvertes(Grid* maGrid)
 * \brief Fonction qui permet de savoir si toutes les cibles (.) sont atteintes
 *
 * \param maGrid pointeur sur la structure Grid
 */


int toutesLesCiblesRecouvertes(struct Grid* maGrid)
{
	return maGrid->ciblesRecouvertes == maGrid->nbrCibles;
}
