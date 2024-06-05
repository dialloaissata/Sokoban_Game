
# PROJET SOKOBAN TECHNIQUE DE DEVELOPPEMENT 2022-2023

## A savoir sur le jeux SDL2
### Joueur: jaune
### Caisse: orange
### Cible: Magenta(violet)
### cible_couvert: Vert
### Joueur_Sur_Cible: Rouge

J'ai travaillé avec Emilie IGERSHEIM mais nous n'avons pas toujours codé nos fonctions de la meme manière (choix des noms de variables ou l'implementation) mais nous avons mis nos idées en communs.

# PREMIERE PARTIE:

#### Prenom:Aissata 

#### NOM:DIALLO

#### NE: 22120044

####  Version GCC utilisé: gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0


#### 	   * * * * *  FONCTION INIT LEVEL  * * * * 

Cette fonction permet d'nitialiser le niveau de jeu . Elle prend en parametres le fichier contenant le niveau de jeux dans notre cas "level.txt" et aussi un pointeur sur la structure Grid.

Modification de la fonction init_level founi au départ. Les variables fournis restent inchangés mais la structure ajouté dans grid.h à apporté de légères modifications dans la fonction. Passage de la structure À PARTIR D'UN POINTEUR "maGrid, allocation dynamique pour letableau game grid, des conditions sur la variable buffer.


####	   * * * * * FONCTION DISPLAY  * * * * * * 

La fonction Display: Elle permet d'afficher la grille de jeux sur le terminal.
Le contenu du fichier level.txt est affiché. Elle prend en paramètres un pointeur sur la structure Grid.

####  	   * * * * *  FONCTION MOVE PLAYER * * * * 

La fonction move-player: Elle permet de faire bouger le joueur (dans notre cas @ ) à l'aide des touches l, k,j,h). Elle prend en parametre une variable direction de type enum et un pointeur vers la structure Grid.
 
####       * * * * * FONCTION FREE GRID * * * * * 

La fonction free grid: Pour liberer de l'espace apres aoir alloué de l'espace pour le tableau game grid. Ceci permet d'éviter les fuites de mémoires.


####       * * * * * PROBLEME RENCONTRÉ  * * * * *

Au départ, je savais pas trop à quoi sert la fonction init level bien que le nom soit parlant, mais le fait de résoudre la fonction display m'a permis de mieux comprendre à quoi elle sert. 

Le second problème, c'était d'afficher le niveau de jeux sur le terminal à l'aide de la fonction display, ce qui m'a fait perdre énormement de temps à passer aux autres fonctions.

Mon dépot Git à eue quelques soucis, raison pour laquelle je n'arrivais pas à faire regulierement de commit. J'ai finalement trouvé le problème qui empaichait cela. Il s'agit d'un clone que j'ai mal éffectué au debut du projet et donc chaque fois que j'essayais un commit il n'arrivait pas. En plus de cela, mon projet avait 2 branches 'main' et 'master', à chaque fois qu'un push est éffectué il partait dans des branches differents mes fichiers. 

Au final j'ai pu resoudre le problème et j'arrive a faire correctement des pushs sur ma branche principal 'main'.




# DEUXIEME PARTIE:


####         * * * * * * * Fonctin toutesLesCiblesRecouvertes * * * * * *
Retourne le nombre de but atteint 

####         * * * * * * * Fonctin display_sdl2 * * * * * *

La fonction display_sdl2: Elle permet d'afficher la grille de jeux en mode sdl (interface graphique)
Le contenu du fichier level.txt est affiché. Elle prend en paramètres un pointeur sur la structure Grid.

####         * * * * * * * Fonctin sdl_init * * * * * *

Cette fonction permet d'nitialiser le niveau de jeu en mode sdl avec une interface graphique . Elle prend en parametres le fichier contenant le niveau de jeux dans notre cas "level.txt" et aussi un pointeur sur la structure Grid.

####         * * * * * * * Fonctin sdl_quit * * * * * *

Ferme le mode sdl

####         * * * * * * * Fonctin event et event_sdl2  * * * * * *
Pour la gestion du clavier avec la fonction fgetc, prend rien en parametre
Ces fontions evenementiels fonctionne avec fgetc, le choix fourni par l'utilisateur en tapant le clavier. Ceci declenche une action 


####       * * * * * PROBLEME RENCONTRÉ  * * * * *

Comprendre le fonctionnement de la SDL m'a pris un peu de temps. Le soucis ce qu'il fallait comprendre chaque fonction a quoi elle sert dans la bibliotheque SDL2.
Mon Git a de nouveau bugé, j'ai essayé de mettre les fichier .c dans un dossier src mais le git ne marchait car la branche main est initialisé dans le dossier sokoban et non dans le src que je voulais creer, donc ca me cree une nouvelle branche master que je ne voulais pas. Ainsi, je me suis contenté de faire un push sur la branche main bien qu'ayant un dossier src. Mais ca n'a aucun impact sur le code source c'est juste pour de l'esthetique.






