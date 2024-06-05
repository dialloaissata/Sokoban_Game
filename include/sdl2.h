/**
 * \file sdl2.h
 * \brief Contient la structure SDLContext (gere la taille de la fenetre), enum Event (different evenement declenché)
 * et les prototypes de fonctions
 */

#ifndef SDL2_HEADER
#define SDL2_HEADER

#pragma once
#include "../install_dir/include/SDL2/SDL.h"
#include "grid.h"

/**
 * \struct SDLContext
 * \brief Cette structure gere la taille de la fenetre(un rectancle en pixel)
 */

typedef struct SDLContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} SDLContext;

/**
 * \enum Event
 * \brief Cette structure contient les informations
 * concernant le déplacement du joueur "dans notre cas '@"
 * k: haut, h: gauche, l: droite, j: bas, q: quitter le jeu, none: aucune action
 */

typedef enum Event
{
  KEY_Left = 'h',
  KEY_Right = 'l',
  KEY_Up = 'k',
  KEY_down = 'j',
  KEY_Quit = 'q',
  None
}Event;


/* @brief 
 * Initialise une variable global `context` de type SDLContext
 * Si il y a erreur pendant l'intialisation:
 *  context.window = NULL ou  *  context.renderer = NULL
 * Les deux cas sont à testé !
 */
void sdl_init();

/**
 *\fn sdl_quit()
 *\brief quitte la sdl
 */
void sdl_quit();

/**
 * \fn display_sdl2( struct Grid *maGrid)
 * \brief Fonction qui permet d'afficher le jeu en mode sdl (avec interface graphique, des couleurs)
 * \param maGrid pointeur sur la structure Grid
 */
void display_sdl2(struct Grid *maGrid);

/**
 * \fn event()
 * \brief pour la gestion de clavier
 */
Event event();

/**
 * \fn event_sdl2()
 * \brief pour la gestion de clavier
 */

Event event_sdl2();

#endif
