#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"
#include "random.h"
#define largeur 338
#define hauteur 338

int enigme(void)
{

    SDL_Surface *screen =NULL, *e[4]={NULL,NULL,NULL,NULL};

    screen = SDL_SetVideoMode(largeur,hauteur,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);

 e[0] = IMG_Load("enigme1.jpg");
 e[1] = IMG_Load("enigme2.jpg");
 e[2] = IMG_Load("enigme3.jpg");
 e[3] = IMG_Load("enigme4.jpg");
 
 

 int i =  0;

 for(;i<4;i++)
 {
    if(!e[i])
 {
   printf("erreur de chargement de l'enigme %d : > %s",i+1,SDL_GetError());
 }

 }


SDL_Rect p_enigme;

p_enigme.x = 0;
p_enigme.y = 0;
int x=nombre();

SDL_Event eventen;
SDL_PollEvent(&eventen);

int cont = 1;
switch(x)
 {

 case 1 :

   SDL_BlitSurface(e[0],NULL,screen,&p_enigme);
   SDL_Flip(screen);
   while(cont)
   {
      SDL_WaitEvent(&eventen);
      switch(eventen.type)
   {
    case SDL_KEYDOWN :
      switch(eventen.key.keysym.sym)
      {
       case SDLK_ESCAPE :
       return 0;
       break;
      }
      break;
    case SDL_MOUSEBUTTONUP :
        switch(eventen.button.button)
        {
        case SDL_BUTTON_LEFT :
            if(eventen.button.x>=45&&eventen.button.x<=120&&eventen.button.y>=206&&eventen.button.y<=227)
                {

                    return 1;
                }else if(eventen.button.x>=230&&eventen.button.x<=309&&eventen.button.y>=206&&eventen.button.y<=227)
                {

                    return 0;
                }
                break;
        }
        break;
       }
    }
    break;

    case 2 :
   SDL_BlitSurface(e[1],NULL,screen,&p_enigme);
   SDL_Flip(screen);
   while(cont)
   {
      SDL_WaitEvent(&eventen);
      switch(eventen.type)
   {
    case SDL_KEYDOWN :
      switch(eventen.key.keysym.sym)
      {
       case SDLK_ESCAPE :
       cont = 0;
       return 0;
       break;
      }
      break;
    case SDL_MOUSEBUTTONUP :
        switch(eventen.button.button)
        {
        case SDL_BUTTON_LEFT :
            if(eventen.button.x>=138&&eventen.button.x<=207&&eventen.button.y>=206&&eventen.button.y<=227)
                {

                    return 1;
                }else if((eventen.button.x>45&&eventen.button.x<120&&eventen.button.y>206&&eventen.button.y<227)||(eventen.button.x>230&&eventen.button.x<309&&eventen.button.y>206&&eventen.button.y<227))
                {

                    return 0;
                }
                break;
        }
        break;
       }
    }
    break;

    case 3 :
   SDL_BlitSurface(e[2],NULL,screen,&p_enigme);
   SDL_Flip(screen);
   while(cont)
   {
      SDL_WaitEvent(&eventen);
      switch(eventen.type)
   {
    case SDL_KEYDOWN :
      switch(eventen.key.keysym.sym)
      {
       case SDLK_ESCAPE :
       return 0;
       cont = 0;
       break;
      }
      break;
    case SDL_MOUSEBUTTONUP :
        switch(eventen.button.button)
        {
        case SDL_BUTTON_LEFT :
            
                if(eventen.button.x>230&&eventen.button.x<309&&eventen.button.y>206&&eventen.button.y<227)
		{

                    return 1;
                }else if((eventen.button.x>138&&eventen.button.x<207&&eventen.button.y>206&&eventen.button.y<227)||(eventen.button.x>45&&eventen.button.x<120&&eventen.button.y>206&&eventen.button.y<227))
                {

                    return 0;
                }
                break;
        }
        break;
       }
    }
    break;

    case 4 :
   SDL_BlitSurface(e[3],NULL,screen,&p_enigme);
   SDL_Flip(screen);
     while(cont)
   {
       SDL_WaitEvent(&eventen);
      switch(eventen.type)
   {
    case SDL_KEYDOWN :
      switch(eventen.key.keysym.sym)
      {
       case SDLK_ESCAPE :
       cont = 0;
       return 0;
       break;
      }
      break;
    case SDL_MOUSEBUTTONUP :
        switch(eventen.button.button)
        {
        case SDL_BUTTON_LEFT :
            if(eventen.button.x>=45&&eventen.button.x<=120&&eventen.button.y>=206&&eventen.button.y<=227)
                {

                    return 1;
                }else if((eventen.button.x>138&&eventen.button.x<207&&eventen.button.y>206&&eventen.button.y<227)||(eventen.button.x>230&&eventen.button.x<309&&eventen.button.y>206&&eventen.button.y<227))
                {

                    return 0;
                }
                break;
        }
        break;
       }

    }
    break;

   } 
}









