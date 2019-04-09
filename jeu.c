#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"jeu.h"




void game(personnage *p)
{


int continuer=1;
//initiation
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO))
fprintf(stderr,"Error SDL : %s\n",SDL_GetError());


//creation fenetre
SDL_Surface *fenetre=NULL;
fenetre=SDL_SetVideoMode(700,672,32,SDL_HWSURFACE);

SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,0,0,0));
SDL_Flip(fenetre);




int colorkey;




SDL_Surface *background;

background=IMG_Load("back.png");

SDL_Rect khanfoura;
khanfoura.x=0;
khanfoura.y=0;
SDL_BlitSurface(background,NULL,fenetre,&khanfoura);



p->image= SDL_LoadBMP("sprite.bmp");
SDL_EnableKeyRepeat(70, 70);	

colorkey = SDL_MapRGB(fenetre->format, 255, 0, 255);
SDL_SetColorKey(p->image, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
p->rcSprite.x = 150;
	p->rcSprite.y = 150;


SDL_BlitSurface(p->image,NULL,fenetre,&p->rcSprite);
	/*intialiser  animation frame */
	p->rcSrc.x = 128;
	p->rcSrc.y = 0;
	p->rcSrc.w =32;
	p->rcSrc.h =32;

SDL_Rect camera;
camera.x=0;
camera.y=0;
camera.h=720;
camera.w=672;





while(continuer)
{

SDL_Event event;
SDL_WaitEvent(&event);



switch(event.type)
{
case SDL_QUIT:
{

 continuer=0;
}

case SDL_KEYDOWN: 
switch (event.key.keysym.sym) {
				
				
				case SDLK_LEFT:
camera.x-=30;
if(camera.x<=0)
camera.x=0;

					if ( p->rcSrc.x == 192 )
						p->rcSrc.x = 224;
					else
						p->rcSrc.x = 192;
                                             p->rcSprite.x -= 10;
					
                                      
					break;
				case SDLK_RIGHT:
 if((p->rcSprite.x>=350)&&(camera.x<260))
                                     {
camera.x+=30;

}
else
{

					p->rcSprite.x += 10;
		
                                      }
if ( p->rcSrc.x == 64 )
						p->rcSrc.x = 96;
					else
						p->rcSrc.x = 64;

					
					
                                        
					break;
				case SDLK_UP:
					if ( p->rcSrc.x == 0 )
						p->rcSrc.x = 32;
					else
						p->rcSrc.x = 0;
					p->rcSprite.y -= 10;
					break;
				case SDLK_DOWN:
					if ( p->rcSrc.x == 128 )
						p->rcSrc.x = 160;
					else
						p->rcSrc.x = 128;
					p->rcSprite.y +=10;
					break;
			}
			break;
	










}


SDL_BlitSurface(background,&camera,fenetre,&khanfoura);
SDL_Flip(fenetre);
SDL_BlitSurface(p->image,&p->rcSrc,fenetre,&p->rcSprite);
SDL_Flip(fenetre);

}









SDL_FreeSurface(fenetre);
SDL_FreeSurface(background);
SDL_FreeSurface(p->image);
Mix_CloseAudio();
SDL_Quit();


}










