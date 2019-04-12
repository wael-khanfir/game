#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"

int main(void)
{
SDL_Surface *pomme=NULL;
SDL_Surface *pos2=NULL;
SDL_Surface *objet1=NULL;
SDL_Surface *screen=NULL;
SDL_Surface *background=NULL;
SDL_Rect positionecran;
SDL_Rect positionobjet1;
SDL_Rect positionpomme;
SDL_Rect positionpos2;
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


positionobjet1.x=250;
positionobjet1.y=350;
objet1 = IMG_Load("objet1.png");
SDL_SetColorKey(objet1, SDL_SRCCOLORKEY, SDL_MapRGB(objet1->format, 255, 255, 255));
SDL_BlitSurface(objet1, NULL, screen, &positionobjet1);
SDL_Flip(screen);
if(objet1==NULL)
{
printf("Unable to load PNG: %s\n",SDL_GetError());
return 1;
}



positionpos2.x=400;
positionpos2.y=350;
pos2 = IMG_Load("pos2.png");
SDL_SetColorKey(pos2, SDL_SRCCOLORKEY, SDL_MapRGB(pos2->format, 255, 255, 255));
SDL_BlitSurface(pos2, NULL, screen, &positionpos2);
SDL_Flip(screen);
if(pos2==NULL)
{
printf("Unable to load PNG: %s\n",SDL_GetError());
return 1;
}


positionpomme.x=700;
positionpomme.y=350;
pomme = IMG_Load("pomme.png");
SDL_SetColorKey(pomme, SDL_SRCCOLORKEY, SDL_MapRGB(pomme->format, 255, 255, 255));
SDL_BlitSurface(pomme, NULL, screen, &positionpomme);
SDL_Flip(screen);
if(pomme==NULL)
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

while(done) //TANT QUE la variable done ne reçoit pas 0
{
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


}
break;
case SDL_MOUSEMOTION:
SDL_BlitSurface(background,NULL,screen,&positionecran);
SDL_BlitSurface(pos2,NULL,screen,&positionpos2);
SDL_BlitSurface(objet1,NULL,screen,&positionobjet1);
SDL_BlitSurface(pomme,NULL,screen,&positionpomme);
SDL_Flip(screen);
break;
if(positionpos2.x)
default: break;
}
background =IMG_Load("fond1.png");
SDL_BlitSurface(background, NULL, screen , &positionecran);
SDL_BlitSurface(objet1,NULL,screen, &positionobjet1);
SDL_BlitSurface(pomme,NULL,screen, &positionpomme);
SDL_BlitSurface(pos2,NULL,screen, &positionpos2);
SDL_Flip(screen);
}
return 0;
}
