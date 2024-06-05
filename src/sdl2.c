/**
 * \file sdl2.c
 * \brief fichier contenant les fonctions sdl_init, display_sdl2, event et event_sdl2 
 */
#include "sdl2.h"

SDLContext context;

/**
 * \fn sdl_init()
 * \brief Fonction qui permet d'initialiser le jeu en mode sdl
 */

void sdl_init() {
  int const width = 1280; // Taille longueur
  int const height = 720; // Taille largeur

  context = (SDLContext){NULL, NULL, .width = 0, .height = 0};
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("ERREUR : Initialisation de SDL > %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  SDL_Window *window =
      SDL_CreateWindow("Sokoban", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    SDL_Log("ERREUR : La creation de la fenetre a echouee > %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
    
  }
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  context = (SDLContext){
      .window = window, .renderer = renderer, .width = width, .height = height};
}


/**
 * \fn display_sdl2( struct Grid *maGrid)
 * \brief Fonction qui permet d'afficher le jeu en mode sdl (avec interface graphique, des couleurs)
 * \param maGrid pointeur sur la structure Grid
 */

void display_sdl2(Grid *maGrid)
{
  float w = context.width / maGrid->column_number; // Initialise la taille du rectangle (longueur)
  float h = context.height / maGrid->row_number;   // Initialise la taille du rectangle (largeur)

  if (SDL_SetRenderDrawColor(context.renderer, 128, 128, 128, 255) != 0)
    printf("Impossible de changer la couleur \n");

  SDL_RenderClear(context.renderer); // Fenêtre en couleur grise

  for (int i = 0; i < maGrid->row_number; i++)
    for (int j = 0; j < maGrid->column_number; j++)
    {
      if (maGrid->game_grid[i][j] == WALL)
      {
        SDL_Rect rec = 
        { 
          .x = j * w,
          .y = i * h,
          .w = w,
          .h = h
        };
        SDL_SetRenderDrawColor(context.renderer, 0, 0, 0, 0); // couleur noir
        SDL_RenderFillRect(context.renderer, &rec);          // On dessine le rectangle
      }
      if (maGrid->game_grid[i][j] == GOAL)
      {
        SDL_Rect rec = 
        { 
          .x = j * w,
          .y = i * h,
          .w = 30,
          .h = 35
        };
        SDL_SetRenderDrawColor(context.renderer, 255, 0, 255, 0); // couleur magenta (violet)
        SDL_RenderFillRect(context.renderer, &rec);            // On dessine le rectangle
      }

      if (maGrid->game_grid[i][j] == BOX)
      {
        SDL_Rect rec = 
        {
          .x = j * w,
          .y = i * h,
          .w = w,
          .h = h
        };
        SDL_SetRenderDrawColor(context.renderer, 255, 127, 51, 184); // couleur orange (brique)
        SDL_RenderFillRect(context.renderer, &rec);                 // On dessine le rectangle
      }

      if (maGrid->game_grid[i][j] == PLAYER)
      {
        SDL_Rect rec = 
        {
          .x = j * w,
          .y = i * h,
          .w = w,
          .h = h
        };
        SDL_SetRenderDrawColor(context.renderer, 255, 255, 0, 0); // couleur jaune (joueur)
        SDL_RenderFillRect(context.renderer, &rec);                // On dessine le rectangle
      }

  
      if (maGrid->game_grid[i][j] == BOX_ON_A_GOAL)
      {
        SDL_Rect rec =
        {
          .x = j * w,
          .y = i * h,
          .w = w,
          .h = h
        };
        SDL_SetRenderDrawColor(context.renderer, 0,150, 0, 250);  // Couleur verte
        SDL_RenderFillRect(context.renderer, &rec);               // On dessine le rectangle
      }

      if (maGrid->game_grid[i][j] == PLAYER_ON_A_GOAL)
      {
        SDL_Rect rec = 
        {
          .x = j * w,
          .y = i * h,
          .w = w,
          .h = h
        };
        SDL_SetRenderDrawColor(context.renderer, 255,0, 0, 250);  // Rouge sang
        SDL_RenderFillRect(context.renderer, &rec);             // On dessine le rectangle
      }
    }
  SDL_RenderPresent(context.renderer);
}



Event event_sdl2()
{
  SDL_Event ev;
  SDL_WaitEvent(&ev);

  switch(ev.type)
  {
    case SDL_QUIT :
      //on a appuyé sur le bouton "quitter" de la fenêtre
      return KEY_Quit;
      break;
    case SDL_KEYUP:
      // on a relaché une touche du clavier, on cherche laquelle
      switch(ev.key.keysym.sym)
      {
        case SDLK_UP:
          return KEY_Up;
          break;
        case SDLK_DOWN:
          return KEY_down;
          break;
        case SDLK_LEFT:
          return KEY_Left;
          break;
        case SDLK_RIGHT:
          return KEY_Right;
          break;
        default:
          return None;
      }
      default :
      return None;
      break;
  }
}


Event event()
{
  Event touche;
  char event = fgetc(stdin);
  switch (event)
  {
  case KEY_Quit:
  {
    touche = KEY_Quit;
    return touche;
    break;
  }
  case KEY_Up:
  {
    touche = KEY_Up;
    return touche;
    break;
  }
  case KEY_down:
  {
    touche = KEY_down;
    return touche;
    break;
  }
  case KEY_Right:
  {
    touche = KEY_Right;
    return touche;
    break;
  }
  case KEY_Left:
  {
    touche = KEY_Left;
    return touche;
    break;
  }
  default:
  {
    touche = None;
    return touche;
    break;
  }
  }
  return None;
}

void sdl_quit() {
  SDL_DestroyWindow(context.window);
  SDL_DestroyRenderer(context.renderer);
  context.window = NULL;
  context.renderer = NULL;
  SDL_Quit();
}
