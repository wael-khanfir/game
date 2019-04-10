#ifndef COOLPER_H_
#define COOLPER_H_
SDL_Color GetPixel(SDL_Surface *surface,int x,int y);
int colli (SDL_Surface *image,SDL_Surface *sprite,SDL_Rect positionSprite,int d);
_Bool collision_Parfaite(SDL_Surface *collisionMap,SDL_Rect col,int direction);
#endif
