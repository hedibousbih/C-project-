#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "mini.h"
#include "collision.h"

int main(int argc, const char* argv[]) 
{
int x,y;

SDL_Surface* source; SDL_Surface* destination;

SDL_Surface *bg=IMG_Load( "backs.png" );

SDL_Surface *ecran;

ecran = SDL_SetVideoMode(720,400, 32, SDL_HWSURFACE);

SDL_WM_SetCaption("lords of imposters", NULL);
mini s;
SDL_Event event;
personnage p;
SDL_Rect posp;
posp.x=30;
posp.y=30;
SDL_Init(SDL_INIT_VIDEO);
s.ecran = SDL_SetVideoMode(500,400, 32, SDL_HWSURFACE);
int continuer = 1;
initialiser_personange(&p);
init_positions(&s);
    while (continuer)
    {   
	Deplacement_personnage(&event,&p,&continuer,&s);   
	init_affich(&s);
	SDL_Flip(ecran);
    }

SDL_Quit();
}
