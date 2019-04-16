
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include"ennemie.h"

int main(){
        SDL_Surface *screen;
        SDL_Surface *image;
Ennemy ennemy;
    
        SDL_Rect positionecran;
       
    printf("hello");
        int continuer=1;
	if(SDL_Init(SDL_INIT_VIDEO)!=0){
                printf("unable to initialize SDL:%s\n",SDL_GetError());
		return 1;
}
screen= SDL_SetVideoMode(1600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL){
	printf("unable to set video mode :%s \n",SDL_GetError());
	return 1;
}
image=SDL_LoadBMP("background.bmp");
if(image==NULL){
	printf("unable to load bitmap :%s \n",SDL_GetError());
return 1;
}

positionecran.x =0;
positionecran.y =0;
positionecran.w =image->w;

initializennemy(&ennemy);
while(continuer)
{
 
 


SDL_BlitSurface(image,NULL,screen,&positionecran);

drawanimatedennemy(screen,&ennemy);
SDL_Flip(screen);}



SDL_FreeSurface(image);

return 0;
}
