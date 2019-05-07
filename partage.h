#ifndef PARTAGE_INCLUDED
#define PARTAGE_INCLUDED

typedef struct joueur joueur;

struct joueur{
SDL_Surface *p[6];
SDL_Rect pp;
int score;
int vies;
int nenigme;
};

typedef struct fond fond;

struct fond{
SDL_Surface *fond;
SDL_Rect pb;
};

void initialiser_joueur1(joueur *j);
void initialiser_joueur2(joueur *j);

void initialiser_fond1(fond *b);
void initialiser_fond2(fond *b);

void initialiser_deuxieme_perso(joueur *j);



void afficher_b1(fond *b,SDL_Surface *screen,SDL_Rect *camera1);
void afficher_b2(fond *b,SDL_Surface *screen,SDL_Rect *camera2);

void afficher_joueur1(joueur *j,SDL_Surface *screen,int *frame);
void afficher_joueur2(joueur *j,SDL_Surface *screen,int *frame);
void afficher_joueur3(joueur *j,SDL_Surface *screen,int *frame);

void deplacement_djoueur1(joueur *j,fond *b,SDL_Surface *screen,SDL_Rect *camera1,int *frame);
void deplacement_gjoueur1(joueur *j,fond *b,SDL_Surface *screen,SDL_Rect *camera1,int *frame);

void deplacement_djoueur2(joueur *j,fond *b,SDL_Surface *screen,SDL_Rect *camera2,int *frame);
void deplacement_gjoueur2(joueur *j,fond *b,SDL_Surface *screen,SDL_Rect *camera2,int *frame);

void animation_djoueur1(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera);
void animation_gjoueur1(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera);

void animation_djoueur2(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera2);
void animation_gjoueur2(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera2);

void acceleration_gjoueur1(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera1);
void acceleration_djoueur1(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera1);

void acceleration_gjoueur2(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera2);
void acceleration_djoueur2(SDL_Surface *screen,fond *b,joueur *j,int *frame,int *speed,SDL_Rect *camera2);



#endif // PARTAGE_INCLUDED


