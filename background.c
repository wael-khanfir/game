  #include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "background.h"

int back(SDL_Surface *image,SDL_Surface *screen, SDL_Rect positionecran)
{if(SDL_Init(SDL_INIT_VIDEO)!=0)
        {
            printf("unable to initialize SDL: %s\n",SDL_GetError());
            return 1;
        }
        screen=SDL_SetVideoMode(338, 338, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
        positionecran.x=0;
        positionecran.y=0;
        image = IMG_Load("background11.jpg");

        SDL_BlitSurface(image , NULL , screen  , &positionecran);
        if(screen==NULL)
        {
            printf("unabble to set video mode :%s\n",SDL_GetError());
            return 1;
        }}

