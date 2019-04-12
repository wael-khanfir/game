#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include "collision.h" 

int main(void)
{
SDL_Surface *screen=NULL;
SDL_Surface *pos2=NULL;
SDL_Surface *personnage2=NULL;
SDL_Surface *background=NULL;
SDL_Rect positionecran;
SDL_Rect positionpos2;
SDL_Rect positionpersonnage2;
SDL_Event test_event;
Mix_Music *musique=NULL;
int done =1;
int boucle_jeux=1;


if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}

screen= SDL_SetVideoMode(1600,400,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}

positionecran.x=0;
positionecran.y=0;
background =IMG_Load("fond1.png");
SDL_BlitSurface(background, NULL, screen , &positionecran);
SDL_Flip(screen);
if(!background)
{
printf("Unable to load background: %s\n",SDL_GetError());
return 1;
}

positionpos2.x=600;
positionpos2.y=100;
pos2 = IMG_Load("pos2.png");
SDL_SetColorKey(pos2, SDL_SRCCOLORKEY, SDL_MapRGB(pos2->format, 255, 255, 255));
SDL_BlitSurface(pos2, NULL, screen, &positionpos2);
SDL_Flip(screen);
if(pos2==NULL)
{
printf("Unable to load PNG: %s\n",SDL_GetError());
return 1;
}

positionpersonnage2.x=200;
positionpersonnage2.y=220;
personnage2 = IMG_Load("detective2.png");
SDL_SetColorKey(personnage2, SDL_SRCCOLORKEY, SDL_MapRGB(personnage2->format, 255, 255, 255));
SDL_BlitSurface(personnage2, NULL, screen, &positionpersonnage2);
SDL_Flip(screen);
if(personnage2==NULL)
{
printf("Unable to load PNG: %s\n",SDL_GetError());
return 1;
}

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
musique=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(musique, -1);

cercle p1,p2;



while(done) //TANT QUE la variable done ne reçoit pas 0
{
p1.x=positionpos2.x;
p1.y=positionpos2.y;
p1.r=100;

p2.x=positionpersonnage2.x;
p2.y=positionpersonnage2.y;
p2.r=100;

int y = collision(p1,p2);

switch(y)
{
  case 0:
  break;

  case 1:
  done = 0;
  break;


}


 
 

SDL_WaitEvent(&test_event); //on attend qu'on récupére un événement
switch(test_event.type) //on teste le type l'événement
{
case SDL_QUIT: //si c'est un événement  QUITTER
done = 0; //on arrête
break;
case SDL_KEYDOWN: //touche enfoncée
switch(test_event.key.keysym.sym)
{
case SDLK_ESCAPE: //appuyer sur la touche Echap
done=0;
break;

case SDLK_LEFT:
positionpersonnage2.x-=80;
break;

case SDLK_RIGHT:
positionpersonnage2.x+=80;
break;

case SDLK_UP:
positionpersonnage2.y-=50;
break;

case SDLK_DOWN:
positionpersonnage2.y+=50;
break;
default: //on ne traite pas les autres événements
break;
}
break;
case SDL_MOUSEMOTION:
positionpersonnage2.x = test_event.motion.x;
positionpersonnage2.y = test_event.motion.y;
SDL_BlitSurface(background,NULL,screen,&positionecran);
SDL_BlitSurface(pos2,NULL,screen,&positionpos2);
SDL_BlitSurface(personnage2,NULL,screen,&positionpersonnage2);
SDL_Flip(screen);
break;
if(positionpos2.x)
default: break;
}
background =IMG_Load("fond1.png");
SDL_BlitSurface(background, NULL, screen , &positionecran);
SDL_BlitSurface(pos2, NULL, screen, &positionpos2);
SDL_BlitSurface(personnage2, NULL, screen, &positionpersonnage2);
SDL_Flip(screen);
}

}
