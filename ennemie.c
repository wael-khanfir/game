#include "ennemie.h"
#include <time.h>

void initializennemy(Ennemy *ennemy)
{
	

        /* Charge le sprite de notre h�ros */
        ennemy->sprite = IMG_Load("walkleft11.png");
        ennemy->w=150;
        ennemy->h=80;
        ennemy->x = 300;
        ennemy->y = 200;
        ennemy->STATE=WAITING;
	ennemy->var1=3;
	ennemy->var2=1;
        //Indique l'�tat et la direction de notre h�ros


        //R�initialise le timer de l'animation et la frame
        ennemy->frameNumber = 0;
       ennemy->frameTimer = TIME_BETWEEN_2_FRAMES;
}

void drawanimatedennemy(SDL_Surface *screen,Ennemy *ennemy )
{

        /* Gestion du timer */
        // Si notre timer (un compte � rebours en fait) arrive � z�ro
        if (ennemy->frameTimer <= 0)
        {
                //On le r�initialise
               ennemy->frameTimer = TIME_BETWEEN_2_FRAMES;

                //Et on incr�mente notre variable qui compte les frames de 1 pour passer � la suivante
                ennemy->frameNumber++;

                //Mais si on d�passe la frame max, il faut revenir � la premi�re
                //Pour conna�tre la frame max, il suffit de diviser la longueur du spritesheet
                //par la longueur de notre h�ros : 480 / 40 = 12 frames
                //Puisque la premi�re frame est la num�ro 0, la derni�re est donc la num�ro 11
               if(ennemy->frameNumber >= ennemy->sprite->w / ennemy->w)
                        ennemy->frameNumber = 0;

        }
        //Sinon, on d�cr�mente notre timer
        else
                ennemy->frameTimer--;




        //Ensuite, on peut passer la main � notre fonction
        drawpennemy(screen,ennemy);


}


void drawpennemy(SDL_Surface *screen,Ennemy *ennemy)
{

        /* Rectangle de destination � blitter */
        SDL_Rect dest;

        // On soustrait des coordonn�es de notre h�ros, ceux du d�but de la map, pour qu'il colle
        //au scrolling :
        int move=20;
if(ennemy->var1==3)
  {ennemy->var2=rand()% 2;
   ennemy->var1=0;}
     if(ennemy->var2==0 && ennemy->x<1600)
      {move=20;
ennemy->x=ennemy->x+move;
ennemy->var1++;
//SDL_FreeSurface(ennemy.sprite);
ennemy->sprite=IMG_Load("walkright11.png");
}
      else if (ennemy->var2==1 && ennemy->x>000)
      {move=-20;
ennemy->x=ennemy->x+move-2;
//SDL_FreeSurface(ennemy.sprite);
ennemy->sprite= IMG_Load("walkleft11.png");
ennemy->var1++;
}
if(ennemy->x<=0)
{ennemy->var2=0;}
if(ennemy->x>=1600)
{ennemy->var2=1;}

	
        dest.x = ennemy->x;
        dest.y = ennemy->y ;
        dest.w =  ennemy->w;
        dest.h =  ennemy->h;
	
printf("random=%d",ennemy->var2);

        /* Rectangle source � blitter */
        SDL_Rect src;


        //Pour conna�tre le X de la bonne frame � blitter, il suffit de multiplier
        //la largeur du sprite par le num�ro de la frame � afficher -> 0 = 0; 1 = 40; 2 = 80...
        src.x =  ennemy->frameNumber * ennemy->w;
        src.y = 0;
        src.w =  ennemy->w;
        src.h =  ennemy->h;

        /* Blitte notre h�ros sur l'�cran aux coordonn�es x et y */

        SDL_BlitSurface( ennemy->sprite, &src, screen, &dest);


}



