
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "coolPer.h"





SDL_Color GetPixel(SDL_Surface *surface,int x,int y)
{
	SDL_Color color ;
	Uint32 col = 0 ;

	//determine position
	char* pPosition = ( char* ) surface->pixels ;

	//offset by y
	pPosition += ( surface->pitch * y ) ;

	//offset by x
	pPosition += ( surface->format->BytesPerPixel * x ) ;

	//copy pixel data
	memcpy ( &col , pPosition , surface->format->BytesPerPixel ) ;

	//convert color
	SDL_GetRGB ( col , surface->format , &color.r , &color.g , &color.b ) ;
	return ( color ) ;
}



int colli (SDL_Surface *image,SDL_Surface *sprite,SDL_Rect positionSprite,int d)
{
SDL_Color  col;
if(d==0)
{col=GetPixel(image,positionSprite.x+sprite->w,positionSprite.y+(sprite->h/2));}
else if (d==1)
{col=GetPixel(image,positionSprite.x,positionSprite.y+(sprite->h/2));}
else if (d==2)
{col=GetPixel(image,positionSprite.x+(sprite->w/2),positionSprite.y);}
else if (d==3)
{col=GetPixel(image,positionSprite.x+(sprite->w/2),positionSprite.y+sprite->h);}
if ((col.r==0)&&(col.b==0)&&(col.g==255))
{return (1);}
else return 0;
}



_Bool collision_Parfaite(SDL_Surface *collisionMap,SDL_Rect col,int direction)
{
if (collisionMap == NULL) 
	collisionMap = SDL_LoadBMP("background1masque.jpg");
    SDL_Color couleur;
    int i;
printf("%d %d %d\n",couleur.r ,couleur.g ,couleur.b );
    if (direction == 4)
    {
	for(i=(col.y+80);i<(col.y + 100);i++)
{
	couleur = GetPixel(collisionMap, col.x, i);
	if((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) )
	break;
}
    }
    else if (direction == 3)
    {
	for(i=(col.y+80);i<(col.y + 100);i++)
{
       couleur = GetPixel(collisionMap, col.x + 25 + 10, i);
	if((couleur.r == 255	 && couleur.g == 255 && couleur.b == 255) )
	break;
}
    }
    else if (direction == 1)
    {
for(i=col.x + 10;i<(col.x + 25);i++)
{
        couleur = GetPixel(collisionMap, i, col.y - 10 + 80);
	if((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) )
	break;
}
    }
    else if (direction == 2)
    {
for(i=col.x + 10;i<(col.x + 25);i++)
{
        couleur = GetPixel(collisionMap, i, col.y + 100 + 10);
	if((couleur.r == 0 && couleur.g == 255 && couleur.b == 0) )
	break;
}
    }
    
	return ((couleur.r == 0 && couleur.g == 255 && couleur.b == 0) );

}


