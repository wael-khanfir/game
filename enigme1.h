#ifndef ENIGME1_H_
#define ENIGME1_H_


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h>

#define largeur 900
#define hauteur 700
struct enigme 
{
	
	SDL_Surface * img[3];
	SDL_Rect position;
}; 
typedef  struct enigme enigme ;


int nombre(void);
int enigme1(SDL_Surface *screen );
void enigme2(SDL_Surface *screen );

#endif // ENIGME1_H_
