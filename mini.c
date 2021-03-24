#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "mini.h"
void init_positions(mini *s)
{

s->posmini.x=180;
s->posmini.y=20;


s->pospoint.x=180;
s->pospoint.y=50;

}

void init_affich(mini *s)
{


s->imagemini=IMG_Load("MINI.png");
s->imagepoint=IMG_Load("point.png");



SDL_BlitSurface(s->imagemini,NULL,s->ecran,&s->posmini);
SDL_BlitSurface(s->imagepoint,NULL,s->ecran,&s->pospoint);

}
void Deplacement_personnage(SDL_Event *event,personnage *p,int *continuer,mini *s)
{

SDL_PollEvent(event);
     switch(event->type)
        {
            case SDL_QUIT:
                (*continuer)=0;
                break;
            case SDL_MOUSEBUTTONDOWN :
if(event->button.button==SDL_BUTTON_LEFT)
   {
if(event->button.x-s->pos.x>p->position.x-s->pos.x)
{
p->position.x+=p->vitesse+p->acceleration*0.2;}

if(event->button.x-s->pos.x<p->position.x-s->pos.x)
{
p->position.x-=p->vitesse+p->acceleration*0.2;}


    }
break;           
 case SDL_KEYDOWN:
                switch(event->key.keysym.sym)
                {
                    case SDLK_UP: 
p->position.y-=3;
                        break;
                    case SDLK_DOWN: 
p->position.y+=3;

                        break;
                    case SDLK_RIGHT: 
p->position.x+=p->vitesse+p->acceleration;
if (p->position.x<3600){
s->pospoint.x+=1;
}
                        break;
                    case SDLK_LEFT: 
p->position.x-=p->vitesse+p->acceleration*0.2;
if (p->position.x>0){
s->pospoint.x-=1;}
                        break;
                }
                break;
             }
 SDL_BlitSurface(s->imagemini,NULL,s->ecran,&s->posmini);
 SDL_BlitSurface(s->imagepoint,NULL,s->ecran,&s->pospoint);
       
}
void initialiser_personange(personnage *p)
{
  
p->position.x=30;
  p->position.y=200;
p->position.h=26;
p->position.w=100;
  p->vie=5;
  p->acceleration=9;
  p->vitesse=10;
  p->score=0;
}





