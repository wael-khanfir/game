
#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
struct personnage
{SDL_Surface *image;
SDL_Rect rcSprite;
SDL_Rect rcSrc;
};typedef struct personnage personnage;
void game(personnage *p);







