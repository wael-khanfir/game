#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include "jeu.h"
int check_collision( SDL_Rect A, SDL_Rect B )
{
    //Les cotes des rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
 
    //Calcul les cotes du rectangle A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;
 
    //Calcul les cotes du rectangle B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;
//Tests de collision
    if( bottomA <= topB )
    {
        return 0;
    }
 
    if( topA >= bottomB )
    {
        return 0;
    }
 
    if( rightA <= leftB )
    {
        return 0;
    }
 
    if( leftA >= rightB )
    {
        return 0;
    }
 
    //Si conditions collision detectee
    return 1;
}
