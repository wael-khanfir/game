/**
* @file jeu.c*/
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include"jeu.h"
#include "enigme.h"
#include "random.h"



/**
* @brief acceleration+animation+scrolling+integration 
* @param p the personnage structur
* @return Nothing
@author THE ART OF GAMES
*/

void game(personnage *p)
{SDL_Surface *screen=NULL, *fail=NULL, *bravo=NULL, *gameover=NULL,*bk=NULL;
fail=IMG_Load("faux.png");
bravo=IMG_Load("vrai.png");
gameover=IMG_Load("gameover.png");
bk=IMG_Load("background11.jpg");
SDL_Rect post;
post.x=0;
post.y=0;

int cont=1,a;







Uint32 t_prev,dt=1;

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

p->acceleration=0.1;
p->velocity=0;

SDL_Surface *background;

background=IMG_Load("back.jpg");

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

SDL_Rect objet;
objet.x=300;
objet.y=290;
SDL_Surface *diamond=NULL;
diamond = IMG_Load("diamond.png");
SDL_SetColorKey(diamond, SDL_SRCCOLORKEY, SDL_MapRGB(diamond->format, 255, 255, 255));
// affichage ennemie +entite secondaire wiem



// rayen perfect pixel


while(continuer)
{t_prev = SDL_GetTicks();
int k=check_collision(p->rcSprite,objet);
if (k==1)
{printf("collision reussite");



 /*SDL_BlitSurface(background,NULL,screen,&khanfoura);
 SDL_Flip(screen);
 SDL_Delay(3000);*/
 a=enigme();
 switch(a)
 {
  case 0 :
  SDL_BlitSurface(fail,NULL,fenetre,&khanfoura);
  SDL_Flip(fenetre);
  SDL_Delay(3000);
  SDL_BlitSurface(gameover,NULL,fenetre,&khanfoura);
  SDL_Flip(fenetre);
  SDL_Delay(3000);
//gestion de vie -- chouchen
  continuer=0;
  break;
  case 1 :
  SDL_BlitSurface(bravo,NULL,fenetre,&khanfoura);
  SDL_Flip(fenetre);
  SDL_Delay(3000);
  break;
 }

}




// collision avec ennemie vie --
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
			case SDLK_ESCAPE:

//sauvergarde oussema
	break;
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
case SDLK_SPACE:
 if((p->rcSprite.x>=350)&&(camera.x<260))
 {p->velocity+=0.5*p->acceleration*dt ;
  camera.x+=30+p->velocity;

}
else
{

					p->rcSprite.x += 20;

                                      }
				case SDLK_RIGHT:
 if((p->rcSprite.x>=350)&&(camera.x<3396))
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


/* affichage enigme oussema
reponse correcte score++ skander
reponse incorrecte score et vie-- skander

*/




                dt=SDL_GetTicks()-t_prev;

}


SDL_BlitSurface(background,&camera,fenetre,&khanfoura);
SDL_BlitSurface(diamond,NULL,fenetre,&objet);
SDL_Flip(fenetre);
SDL_BlitSurface(p->image,&p->rcSrc,fenetre,&p->rcSprite);
SDL_Flip(fenetre);

}









SDL_FreeSurface(fenetre);
SDL_FreeSurface(background);
SDL_FreeSurface(p->image);
SDL_FreeSurface(fail);
SDL_FreeSurface(bravo);
Mix_CloseAudio();
SDL_Quit();


}











