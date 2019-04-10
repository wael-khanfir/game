#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"jeu.h"









int main()
{personnage p;
int continuer=1;
//initiation
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());



SDL_Surface *ecran=NULL;
ecran=SDL_SetVideoMode(700,531,32,SDL_HWSURFACE);

SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
SDL_Flip(ecran);


//creation background
SDL_Surface *background[0];
background[0]=IMG_Load("menu.png");


SDL_Rect backgroundpos;
backgroundpos.x=0;
backgroundpos.y=0;
SDL_BlitSurface(background[0],NULL,ecran,&backgroundpos);
SDL_Flip(ecran);
 if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
  printf("%s",Mix_GetError());
}
Mix_Music *music;
music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);



background[1]=IMG_Load("play.png");
background[2]=IMG_Load("story.png");
background[3]=IMG_Load("quit.png");
background[4]=IMG_Load("playy.png");



if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
   {
      printf("%s", Mix_GetError());
   }
Mix_Music *musique; //Création du pointeur de type Mix_Music



int x;
while (continuer)
{
SDL_Event event;
SDL_WaitEvent(&event);

switch(event.type)
{case SDL_QUIT:
{

x=0;
 continuer=0;
}
 

case SDL_MOUSEBUTTONDOWN:
{
if(event.button.button==SDL_BUTTON_LEFT)
{
if(((event.button.x>185)&&(event.button.x<250))&&((event.button.y>130)&&
(event.button.y<170)))
{
SDL_Delay(300);
SDL_BlitSurface(background[1],NULL,ecran,&backgroundpos);
SDL_Flip(ecran);
musique = Mix_LoadMUS("ww.mp3"); //Chargement de la musique
//repetition de la musique
Mix_PlayMusic(musique, -1);
SDL_Delay(100);
Mix_FreeMusic(musique);
game(&p);
}
else if(((event.button.x>179)&&(event.button.x<278))&&((event.button.y>205)&&
(event.button.y<235)))
{
x=2 ; 
SDL_Delay(300);
SDL_BlitSurface(background[2],NULL,ecran,&backgroundpos);
SDL_Flip(ecran);
musique = Mix_LoadMUS("ww.mp3"); //Chargement de la musique
//repetition de la musique
Mix_PlayMusic(musique, -1);
SDL_Delay(100);
Mix_FreeMusic(musique);

}
else if(((event.button.x>186)&&(event.button.x<255))&&((event.button.y>337)&&
(event.button.y<367)))
{
SDL_Delay(300);
SDL_BlitSurface(background[3],NULL,ecran,&backgroundpos);
SDL_Flip(ecran);
musique = Mix_LoadMUS("ww.mp3"); //Chargement de la musique
//repetition de la musique
Mix_PlayMusic(musique, -1);

SDL_Delay(100);
continuer=0;
}
 
}

}


}}


SDL_FreeSurface(background[4]);
SDL_FreeSurface(background[0]);
SDL_FreeSurface(background[1]);
SDL_FreeSurface(background[2]);
SDL_FreeSurface(background[3]);
SDL_FreeSurface(ecran);
TTF_Quit();
Mix_FreeMusic(music);
Mix_FreeMusic(musique);
Mix_CloseAudio();
SDL_Quit();






 
return 0;
}
