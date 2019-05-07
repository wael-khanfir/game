
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
int  velocity;
int acceleration;
};typedef struct personnage personnage;
void game(personnage *p);
int check_collision( SDL_Rect A, SDL_Rect B );






