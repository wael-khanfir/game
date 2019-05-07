#include "enigme1.h"
int nombre(void)
{
    srand(time(NULL));
    int x=rand()%4 +1;
    return x;
}
void initialiser_enigme (enigme *e)
{
	e->img[0] = IMG_Load("enigme1.jpg");
 	e->img[1] = IMG_Load("enigme2.jpg");
	e->img[2] = IMG_Load("enigme3.jpg");
        e->img[3] = IMG_Load("enigme4.jpg");
	
	e->position.x=0;
	e->position.y=0;
}
int generation_enigme(SDL_Surface *ecran ,enigme e,int x)
{
	
	if(x==1)
		{SDL_BlitSurface(e.img[0] ,NULL,ecran,&e.position);}
	else if(x==2)
		{SDL_BlitSurface(e.img[1] ,NULL,ecran,&e.position);}
        else if(x==3)
		{SDL_BlitSurface(e.img[2] ,NULL,ecran,&e.position);}
        else if(x==4)
		{SDL_BlitSurface(e.img[3] ,NULL,ecran,&e.position);}


}

int enigme1(SDL_Surface *screen)
{ 
SDL_Surface *enigme[3]={NULL,NULL,NULL};
SDL_Rect pos_enigme1;

enigme[1] = IMG_Load("enigme2.jpg");
enigme[2] = IMG_Load("enigme3.jpg");
enigme[0] = IMG_Load("enigme1.jpg");
enigme[3] = IMG_Load("enigme4.jpg");

pos_enigme1.x=0;
pos_enigme1.y=0;

int x = nombre();

SDL_Event event;
int cont=1;
switch(x)
{
case 1 : 

SDL_BlitSurface(enigme[0],NULL,screen,&pos_enigme1);
SDL_Flip(screen);

while(cont)
{
  SDL_WaitEvent(&event);
  switch(event.type)
{
case SDL_MOUSEBUTTONUP :
   switch(event.button.button)
  {
   case SDL_BUTTON_LEFT :
    if(event.button.x>45&&event.button.x<120&&event.button.y>206&&event.button.y<227)
{
 return 1;
}else if((event.button.x>138&&event.button.x<207&&event.button.y>206&&event.button.y<227)||(event.button.x>230&&event.button.x<309&&event.button.y>206&&event.button.y<227))

{
 return 0;
}
break;
}
break;
}
}
break;

case 2 :
SDL_BlitSurface(enigme[1],NULL,screen,&pos_enigme1);
SDL_Flip(screen);

while(cont)
{
  SDL_WaitEvent(&event);
  switch(event.type)
{
 	
   break;
   case SDL_MOUSEBUTTONUP :
   switch(event.button.button)
  {
   case SDL_BUTTON_LEFT :
    if(event.button.x>138&&event.button.x<207&&event.button.y>206&&event.button.y<227)
{
 return 1;
}else if((event.button.x>45&&event.button.x<120&&event.button.y>206&&event.button.y<227)||(event.button.x>230&&event.button.x<309&&event.button.y>206&&event.button.y<227))
{
 return 0;
}
break;
}
break;
} 
}
break;

case 3 :

SDL_BlitSurface(enigme[2],NULL,screen,&pos_enigme1);
SDL_Flip(screen);

while(cont)
{
  SDL_WaitEvent(&event);
  switch(event.type)
{

   break;
   case SDL_MOUSEBUTTONUP :
   switch(event.button.button)
  {
   case SDL_BUTTON_LEFT :
    if(event.button.x>230&&event.button.x<309&&event.button.y>206&&event.button.y<227)
{
 return 1;
}else if((event.button.x>138&&event.button.x<207&&event.button.y>206&&event.button.y<227)||(event.button.x>45&&event.button.x<120&&event.button.y>206&&event.button.y<227))
{
 return 0;
}
break;
}
break;
}
} 
break;

case 4 : 

SDL_BlitSurface(enigme[3],NULL,screen,&pos_enigme1);
SDL_Flip(screen);

while(cont)
{
  SDL_WaitEvent(&event);
  switch(event.type)
{
case SDL_MOUSEBUTTONUP :
   switch(event.button.button)
  {
   case SDL_BUTTON_LEFT :
    if(event.button.x>45&&event.button.x<120&&event.button.y>206&&event.button.y<227)
{
 return 1;
}else if((event.button.x>138&&event.button.x<207&&event.button.y>206&&event.button.y<227)||(event.button.x>230&&event.button.x<309&&event.button.y>206&&event.button.y<227))
{
 return 0;
}
break;
}
break;
}
}
break;


}

int j;

for(j=0;j<2;j++)
{
SDL_FreeSurface(enigme[j]);
}
}
void enigme2(SDL_Surface *screen )
{
SDL_Surface *background=NULL,*vrai=NULL,*faux=NULL;
SDL_Rect p_background, p_vrai, p_faux;


background=IMG_Load("back.jpg");
p_background.x=0;
p_background.y=0;

vrai=IMG_Load("vrai.png");
p_vrai.x=0;
p_vrai.y=0;

faux=IMG_Load("faux.png");
p_faux.x=0;
p_faux.y=0;

SDL_BlitSurface(background,NULL,screen,&p_background);
SDL_Flip(screen);
SDL_Event event1;

int continuer = 1;
while(continuer)
{
SDL_WaitEvent(&event1);
switch(event1.type)
{
case SDL_KEYDOWN : 
switch(event1.key.keysym.sym)
{
case SDLK_ESCAPE :
continuer = 0;
break;
}


int a = 0;
a = enigme1( screen);
switch(a)
{

  case 0 :
  SDL_BlitSurface(faux,NULL,screen,&p_faux);
  SDL_Flip(screen);
 SDL_Delay(4000);
  SDL_BlitSurface(background,NULL,screen,&p_background);
 
  
  SDL_Flip(screen);
  
  break;
  case 1 :
 SDL_BlitSurface(vrai,NULL,screen,&p_vrai);

 SDL_Flip(screen);
 SDL_Delay(4000);
 SDL_BlitSurface(background,NULL,screen,&p_background);
 SDL_Flip(screen);
 break; 
}

}

}

SDL_FreeSurface(vrai);
SDL_FreeSurface(faux);
SDL_Quit();
}


