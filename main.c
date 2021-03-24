#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "mini.h"

int main(int argc, const char* argv[]) 
{
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
	SDL_Flip(s.ecran);
    }

SDL_Quit();
}
