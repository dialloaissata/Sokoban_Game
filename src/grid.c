/**
 * \file grid.c
 * \brief fichier contenant les fonctions init_level, display, et free_grid
 */

#include "grid.h"
#include <stdlib.h>
#include <stdio.h>
 
/**
 * \fn struct Grid *init_level(const char *file_path, struct Grid *maGrid)
 * \brief Fonction qui permet d'initialiser le niveau de jeu. 
 *
 * \param file_path pointeur sur le fichier level.txt
 * \param maGrid pointeur sur la structure Grid
 */
struct Grid *init_level(const char *file_path, struct Grid *maGrid)
{
	char line[100] = {0};
	int number_column = 0; /// number_column: nombre de colonne
	int number_row = 0;	   /// number_row: nombre de ligne
	int number_goals = 0; ///  number_goal: nombre de but à atteindre

	// ouverture du fichier en mode lecture
	FILE *file = fopen(file_path, "r");
	if (!file)
	{
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}
	
	// on lit la première ligne du fichier
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);

	// allocation dynamique de la place dans le tableau
	maGrid->game_grid = (enum CaseType **)malloc(number_row * sizeof(enum CaseType *)); // alloue la place des lignes de game_grid
	for (int i = 0; i < number_row; i++)
	{
		maGrid->game_grid[i] = (enum CaseType *)malloc(number_column * sizeof(enum CaseType *)); // alloue la place des colonnes de game_grid
	}

	int current_row = 0; // ligne courante du tableau

	maGrid->column_number = number_column; // affectation de la structure avec nombre de colonne
	maGrid->row_number = number_row;	   // affectation de la structure avec nombre de ligne
	maGrid->nbrCibles = number_goals;     // affectation nombres de but a atteindre dans la grille 
	maGrid->ciblesRecouvertes = 0;        // Nombre de but atteint initialisé a 0 au depart

	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while (fgets(line, 100, file) != NULL)
	{
		char *buffer = line;
		int current_column = 0;			   // colonne courante du tableau
		while (*buffer && *buffer != '\n') // Tant que buffer est different a saut de ligne
		{
			if (*buffer == '@')
			{
				// completion du champs Player avec la position du joueur
				maGrid->joueur.x = current_row;
				maGrid->joueur.y = current_column;
			}
			maGrid->game_grid[current_row][current_column] = *buffer;
			current_column++;
			buffer += 1;
		}
		current_row += 1;
	}
	// fermeture du fichier
	fclose(file);
	return maGrid;
}

/**
 * \fn display(struct Grid *pointeurNiveau)
 * \brief Fonction qui permet d'afficher la grille de jeux sur le terminal. 
 *
 * \param pointeurNiveau pointeur sur la structure Grid
 */
void display(struct Grid *pointeurNiveau)
{
	for (int i = 0; i < pointeurNiveau->row_number; i++)
	{
		for (int j = 0; j < pointeurNiveau->column_number; j++)
		{
			printf("%c", pointeurNiveau->game_grid[i][j]); // Affichage du tableau game grid (level.txt)
		}
		printf("\n");
	}
}

/**
 * \fn free_Grid(struct Grid *maGrid)
 * \brief Fonction qui permet de liberer de l'espace mémoire. Apres que de l'espace 
 * ait été alloué dans la fonction init level pour le tableau gamegrid.
 *
 * \param maGrid pointeur sur la structure Grid
 */
void free_Grid(struct Grid *maGrid)
{
	for (int i = 0; i < maGrid->row_number; i++)
	{
		free(maGrid->game_grid[i]);
	}
	free(maGrid->game_grid);
}
