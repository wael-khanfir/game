#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "partage.h"
#define largeur 1600
#define hauteur 400

void initialiser_joueur1(joueur *j)
{
    j->p[0]=IMG_Load("p1.png");
    j->p[1]=IMG_Load("p2.png");
    j->p[2]=IMG_Load("p3.png");
    j->p[3]=IMG_Load("p4.png");
 
    j->pp.x = 10;
    j->pp.y = 235;

}

void initialiser_joueur2(joueur *j)
{
    j->p[0]=IMG_Load("p1.png");
    j->p[1]=IMG_Load("p2.png");
    j->p[2]=IMG_Load("p2.png");
    j->p[3]=IMG_Load("p4.png");
    

    j->pp.x = largeur/2 + 10;
    j->pp.y = 235;

}

void initialiser_fond1(fond *b)
{
    b->fond=IMG_Load("fond.png");
    b->pb.x=0;
    b->pb.y=0;
    b->pb.w=largeur;
    b->pb.h=hauteur/2;
}

void initialiser_fond2(fond *b)
{
    b->fond=IMG_Load("fond.png");
    b->pb.x=largeur/2;
    b->pb.y=0;
    b->pb.w=largeur;
    b->pb.h=hauteur;
}

void initialiser_deuxieme_perso(joueur *j)
{
    j->p[0]=IMG_Load("p1.png");
    j->p[1]=IMG_Load("p2.png");
    j->p[2]=IMG_Load("p3.png");
    j->p[3]=IMG_Load("p4.png");

    j->pp.x = largeur/2-90;
    j->pp.y = 235;
}



void afficher_b1(fond *b,SDL_Surface *screen,SDL_Rect *camera1)
{
    SDL_BlitSurface(b->fond,camera1,screen,&b->pb);
    SDL_Flip(screen);
}

void afficher_b2(fond *b,SDL_Surface *screen,SDL_Rect *camera2)
{
    SDL_BlitSurface(b->fond,camera2,screen,&b->pb);
    SDL_Flip(screen);
}

void afficher_joueur1(joueur *j,SDL_Surface *screen,int *frame)
{
    SDL_BlitSurface(j->p[*frame],NULL,screen,&j->pp);
    SDL_Flip(screen);
}

void afficher_joueur2(joueur *j,SDL_Surface *screen,int *frame)
{
    SDL_BlitSurface(j->p[*frame],NULL,screen,&j->pp);
    SDL_Flip(screen);
}

void afficher_joueur3(joueur *j,SDL_Surface *screen,int *frame)
{
    SDL_BlitSurface(j->p[*frame],NULL,screen,&j->pp);
    SDL_Flip(screen);
}

void deplacement_djoueur1(joueur *j,fond *b,SDL_Surface *screen,SDL_Rect *camera1,int *frame)
{
    int speed=10;
    camera1->x+=speed;
    if(camera1->x>=(14222-camera1->w))
    {
        camera1->x=14222-camera1->w;
    }
     afficher_b1(b,screen,camera1);
     afficher_joueur1(j,screen,frame);
}

void deplacement_gjoueur1(joueur *j,fond *b,SDL_Surface *screen,SDL_Rect *camera1,int *frame)
{
    int speed=10;
    camera1->x-=speed;
    if(camera1->x<=(camera1->w))
    {
        camera1->x=camera1->w;
    }
     afficher_b1(b,screen,camera1);
     afficher_joueur1(j,screen,frame);
}

void deplacement_djoueur2(joueur *j,fond *b,SDL_Surface *screen,SDL_Rect *camera2,int *frame)
{
    int speed=10;
    camera2->x+=speed;
    if(camera2->x>=(14222-camera2->w))
    {
        camera2->x=14222-camera2->w;
         j->pp.x+=speed;
    }
     afficher_b2(b,screen,camera2);
     afficher_joueur2(j,screen,frame);
}

void deplacement_gjoueur2(joueur *j,fond *b,SDL_Surface *screen,SDL_Rect *camera2,int *frame)
{
    int speed=10;
    camera2->x-=speed;
    if(camera2->x<=(camera2->w))
    {
        camera2->x=camera2->w;
         j->pp.x+=speed;
    }
     afficher_b1(b,screen,camera2);
     afficher_joueur2(j,screen,frame);
}

void animation_djoueur1(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera1)
{
    afficher_b1(b,screen,camera1);
    if((*frame)>=3)
    {
        *frame=0;
    }
     afficher_joueur1(j,screen,frame);
     SDL_Delay(50);
}

void animation_gjoueur1(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera1)
{
    afficher_b1(b,screen,camera1);
    if((*frame)<=2||(*frame)>=6)
    {
        *frame=3;
    }
    afficher_joueur1(j,screen,frame);
    j->pp.x-=(*speed);
    SDL_Delay(50);
}

void animation_djoueur2(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera2)
{
    afficher_b1(b,screen,camera2);
    if((*frame)>=3)
    {
        *frame=0;
    }
     afficher_joueur2(j,screen,frame);
     SDL_Delay(50);
}

void animation_gjoueur2(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera2)
{
    afficher_b1(b,screen,camera2);
    if((*frame)<=2||(*frame)>=6)
    {
        *frame=3;
    }
    afficher_joueur2(j,screen,frame);
    j->pp.x-=(*speed);
    SDL_Delay(50);
}



void acceleration_gjoueur1(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera1)
{
    if((*frame)<=2||(*frame)>=6)
    {
        *frame=3;
    }
    camera1->x-=3*(*speed);
    if(camera1->x<=(camera1->w))
    {
        camera1->x=camera1->w;
    }
    afficher_b1(b,screen,camera1);
    afficher_joueur1(j,screen,frame);
    SDL_Delay(20);
}

void acceleration_djoueur1(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera1)
{
    if((*frame)>=3)
    {
        *frame=0;
    }
    camera1->x+=3*(*speed);
    if(camera1->x>=(14222-camera1->w))
    {
        camera1->x=14222-camera1->w;
    }
     afficher_b1(b,screen,camera1);
     afficher_joueur1(j,screen,frame);
    SDL_Delay(20);
}

void acceleration_gjoueur2(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera2)
{
    afficher_b1(b,screen,camera2);
    if((*frame)<=2||(*frame)>=6)
    {
        *frame=3;
    }
    j->pp.x-=((*speed)*3);
    afficher_joueur2(j,screen,frame);
    SDL_Delay(20);
}

void acceleration_djoueur2(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera2)
{
    if((*frame)>=3)
    {
        *frame=0;
    }
    camera2->x+=3*(*speed);
    if(camera2->x>=(14222-camera2->w))
    {
        camera2->x=14222-camera2->w;
    }
     afficher_b1(b,screen,camera2);
     afficher_joueur2(j,screen,frame);
    SDL_Delay(20);
}


