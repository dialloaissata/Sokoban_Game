/**
 * \file main.c
 * \brief fichier contenant tous les test de fonctions : Affiche la grille de jeux
 * Deux mode d'affichage: en mode console ou en mode sdl (interface graphique)
 * \author DIALLO Aissata
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include "sdl2.h"
#include "grid.h"

int main(int argc, char *argv[])
{
	struct Grid maGrid;
	init_level("level1.txt", &maGrid);

	Event (*handle_event)(void);
	void (*handle_display)(struct Grid * grid);

	int SDLOutput = 1;
	int consoleOutput = 1;
	if (argc > 1)
	{
		consoleOutput = strcmp(argv[1], "--console");
		SDLOutput = strcmp(argv[1], "--sdl2");
	}

	if (argc == 1 || consoleOutput == 0)
	{
		handle_event = event;
		handle_display = display;
	}

	else if (SDLOutput == 0)
	{
		sdl_init();
		handle_display = display_sdl2;
		handle_event = event_sdl2;
	}
	else
	{
		printf("Pour l'affichage console: ./main --console ou ./main     Pour l'affichage en sdl2: ./main --sdl2\n");
		exit(EXIT_FAILURE);
	}
	handle_display(&maGrid);
	bool run = true;
	while (run)
	{
		Event choix = handle_event();
		switch (choix)
		{

			case KEY_Quit:
			{
				run = false;
				break;
			}
			case KEY_Left:
			{
				move_player(Left, &maGrid);
				break;
			}
			case KEY_down:
			{
				move_player(Bottom, &maGrid);
				break;
			}
			case KEY_Up:
			{
				move_player(Top, &maGrid);
				break;
			}
			case KEY_Right:
			{
				move_player(Right, &maGrid);
				break;
			}
			default:
				break;
		}
		handle_display(&maGrid);
		if(toutesLesCiblesRecouvertes(&maGrid))
		{
			printf("Bravo, vous avez gagné !\n");
			run = false;
		}
	}
	free_Grid(&maGrid);
	sdl_quit();
	return 0;
}
