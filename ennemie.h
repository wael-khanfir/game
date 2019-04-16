#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
typedef enum STATE STATE ;
enum STATE
{WAITING,FOLLOWING,ATTACKING };
typedef struct Ennemy
{
    //Sprite du héros (pas d'animation pour l'instant)
	SDL_Surface *sprite;

	/* Coordonnées du héros */
	int x, y;
	/* Largeur, hauteur du sprite */
     int h, w;
	/* Variables utiles pour l'animation */
	int frameNumber, frameTimer;
        STATE STATE ;
	int  distance;
	int var1,var2;

  SDL_Surface *bar;
//STATE STATE;

     float dirX;

} Ennemy;


#define TIME_BETWEEN_2_FRAMES 1
void initializennemy(Ennemy *ennemy);
void drawanimatedennemy(SDL_Surface *screen,Ennemy *ennemy );
void drawpennemy(SDL_Surface *screen,Ennemy *ennemy);

