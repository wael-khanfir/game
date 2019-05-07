#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "partage.h"

#define largeur 1590
#define hauteur 400

int main(int argc, char *argv[])
{
    SDL_Surface *screen=NULL,*trait=NULL;
    joueur j1,j2,j3;
    fond b1,b2;
    int continuer = 1,frame=0,speed=5;

    SDL_Rect camera1, camera2, p_trait;

    camera1.x=0;
    camera1.y=15;
    camera1.w=largeur/2;
    camera1.h=hauteur;

    camera2.x=0;
    camera2.y=15;
    camera2.w=largeur/2;
    camera2.h=hauteur;

    p_trait.x=largeur/2;
    p_trait.y=0;

    SDL_Init(SDL_INIT_VIDEO);

    screen=SDL_SetVideoMode(largeur,hauteur,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    initialiser_fond1(&b1);
    initialiser_fond2(&b2);

    initialiser_joueur1(&j1);
    initialiser_joueur2(&j2);
    initialiser_deuxieme_perso(&j3);

    trait = IMG_Load("trait.png");

    afficher_b1(&b1,screen,&camera1);
    afficher_b2(&b2,screen,&camera2);

    afficher_joueur1(&j1,screen,&frame);
    afficher_joueur2(&j2,screen,&frame);
    afficher_joueur3(&j3,screen,&frame);
    SDL_BlitSurface(trait,NULL,screen,&p_trait);
    SDL_Flip(screen);

    SDL_Event event;
    SDL_EnableKeyRepeat(10,10);
    while(continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
        continuer=0;
        break;
        case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE :
                continuer = 0;
                break;
                case SDLK_RIGHT :
                deplacement_djoueur1(&j1,&b1,screen,&camera1,&frame);
                animation_djoueur1(screen,&b1,&j1,&frame,&speed,&camera1);
                frame++;
                break;
                case SDLK_LEFT :
                deplacement_gjoueur1(&j1,&b1,screen,&camera1,&frame);
                animation_gjoueur1(screen,&b1,&j1,&frame,&speed,&camera1);
                frame++;
                break;
                case SDLK_d :
                deplacement_djoueur2(&j2,&b2,screen,&camera2,&frame);
                animation_djoueur2(screen,&b2,&j2,&frame,&speed,&camera2);
                frame++;
                break;
                case SDLK_a :
                deplacement_gjoueur2(&j2,&b2,screen,&camera2,&frame);
                animation_gjoueur2(screen,&b2,&j2,&frame,&speed,&camera2);
                frame++;
                break;
                case SDLK_m :
                deplacement_djoueur1(&j1,&b1,screen,&camera1,&frame);
                acceleration_djoueur1(screen,&b1,&j1,&frame,&speed,&camera1);
                frame++;
                break;
                case SDLK_n :
                deplacement_gjoueur1(&j1,&b1,screen,&camera1,&frame);
                acceleration_gjoueur1(screen,&b1,&j1,&frame,&speed,&camera1);
                frame++;
                break;
                case SDLK_v :
                deplacement_djoueur2(&j2,&b2,screen,&camera2,&frame);
                acceleration_djoueur2(screen,&b2,&j2,&frame,&speed,&camera2);
                frame++;
                break;
                case SDLK_c :
                deplacement_gjoueur2(&j2,&b2,screen,&camera2,&frame);
                acceleration_gjoueur2(screen,&b2,&j2,&frame,&speed,&camera2);
                frame++;
                break;
            }
            break;
        }
        SDL_BlitSurface(trait,NULL,screen,&p_trait);
        SDL_Flip(screen);

    }

}
