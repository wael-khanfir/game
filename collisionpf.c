
          

#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
















int main(void)
{
	
    SDL_Surface *screen;
    SDL_Surface *image;
    SDL_Surface *sprite;
    SDL_Rect positionecran,obs;
    SDL_Rect positionSprite;
    SDL_Rect rect;
	obs.h=10;
    rect.x = 0;
    rect.y = 0;
    rect.h = 672;
    rect.w = 960;
    Mix_Music *musique;
    SDL_Event test_event;
    int done =1;
    int boucle_jeux=1;
    int test=0;
int d;
    positionSprite.x=200;
    positionSprite.y=200;
positionSprite.h=100;
    char pause;

    while(boucle_jeux)
    {
        if(SDL_Init(SDL_INIT_VIDEO)!=0)
        {
            printf("unable to initialize SDL: %s\n",SDL_GetError());
            return 1;
        }
        screen=SDL_SetVideoMode(960, 672, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
        positionecran.x=0;
        positionecran.y=0;
        image = IMG_Load("background1.jpg");

        SDL_BlitSurface(image , NULL , screen  , &positionecran);
SDL_Surface *surf = IMG_Load("background1.png");
SDL_Surface * surfM = IMG_Load("background1Masque.jpg");
        if(screen==NULL)
        {
            printf("unabble to set video mode :%s\n",SDL_GetError());
            return 1;
        }

 sprite = IMG_Load("detective.png" );
        SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, 255, 255, 255));
        SDL_BlitSurface(sprite , NULL , screen  , &positionSprite);
        positionSprite.x = 0;
        positionSprite.y =0;
        SDL_Flip(screen);
        if(image==NULL)
        {
            printf("unable to laod bitmap: %s\n",SDL_GetError());
            return 1;
        }




SDL_Color GetPixel(SDL_Surface *surface,int x,int y);








        
  while(done)
        {
            SDL_WaitEvent(&test_event);
            switch(test_event.type)
            {
            case SDL_QUIT:
                done=0;
                break ;
            case SDL_KEYDOWN:
                switch(test_event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done=0;
                    break;
                case SDLK_LEFT:
                    positionSprite.x-=10;



                    if(positionSprite.x <= rect.y) {
                        positionSprite.x= positionSprite.x + 500;
                    }
                    break;
                case SDLK_RIGHT:
                    positionSprite.x+=10;

                    if(positionSprite.x >= (rect.w-70)) {
                        positionSprite.x= positionSprite.x - 50;
                    }
                    break;
                case SDLK_UP:
                    positionSprite.y-=10;
                    if(positionSprite.y <= rect.x) {
                        positionSprite.y= positionSprite.y + 500;
                    }
                    break;
                case SDLK_DOWN:
                    positionSprite.y+=10;
			
                    if(positionSprite.y >= (rect.h - 1)) {
                        positionSprite.y= positionSprite.y - 100;
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }



int colli (SDL_Surface *image,SDL_Surface *sprite,SDL_Rect positionSprite,int d);









_Bool collision_Parfaite(SDL_Surface *collisionMap,SDL_Rect col,int direction);

      















image = IMG_Load("background1masque.jpg");
            SDL_BlitSurface(image , NULL , screen  , &positionecran);
            SDL_Flip(screen);
            SDL_BlitSurface(sprite , NULL , screen  , &positionSprite);
            SDL_Flip(screen);
        }

{
        SDL_FreeSurface(image);
        SDL_FreeSurface(sprite);
 
        SDL_Quit;
        return (0);
    }

}
}




















