#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include "collisionb.h"
int collision(SDL_Rect pos1,SDL_Rect pos2)
{
    if( (pos1.x+pos1.w<pos2.x)||(pos1.x>pos2.x+pos2.w) )/*|| (pos1.y+pos1.h<pos2.y) || (pos1.y>pos2.y+pos2.h) )*/
      { 
        return 0;
       }
    else
	{
        return 1;
	}
    /*
    //Les cotes des rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calcul les cotes du rectangle A
    leftA = pos1.x;
    rightA = pos1.x + A->w;
    topA = pos1.y;
    bottomA = pos1.y + A->h;

    //Calcul les cotes du rectangle B
    leftB = pos2.x;
    rightB = pos2.x + B->w;
    topB = pos2.y;
    bottomB = pos2.y + B->h;

    //Tests de collision
    if( bottomA <= topB )
    {
        return 1;
    }

    if( topA >= bottomB )
    {
        return 1;
    }

    if( rightA <= leftB )
    {
        return 1;
    }

    if( leftA >= rightB )
    {
        return 1;
    }

    //Si conditions collision detectee
    return 0;*/

    //a partir de lemail

}

