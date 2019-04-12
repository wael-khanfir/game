#include <stdio.h>
#include <stdlib.h>
#include "collision.h"
#include <SDL/SDL.h>
#include <math.h>

int collision(cercle p1, cercle p2)
{ 

SDL_Rect pp1,pp2;
int d=0;


  pp1.x = p1.x + p1.r;
  pp1.y  =p1.y + p1.r;
  pp2.x = p2.x + p2.r;
  pp2.y  =p2.y + p2.r;
  d=((pp2.x-pp1.x)*(pp2.x-pp1.x) + (pp2.y-pp1.y)*(pp2.y-pp1.y));
  if(d <= (p1.r+p2.r)*(p1.r+p2.r))
   {
    return 1;
  }else
  {
    return 0;
  }
}


