#ifndef mini_h
#define mini_h
#define P_WIDTH 100
#define P_HEIGHT 26
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
typedef struct
{
    SDL_Rect position;
    SDL_Surface *sprite;
    int vitesse;
    int acceleration;
    int vie;
    int score;
    int status;
    float x,y;
    float vx,vy;
}personnage;

typedef struct
{

SDL_Surface *ecran;
SDL_Surface* imagemini;
SDL_Rect posmini;
SDL_Surface* imagepoint;
SDL_Rect pospoint;
    SDL_Rect pos;
}mini;
void init_positions(mini *s);
void init_affich(mini *s);
void Deplacement_personnage(SDL_Event *event,personnage *p,int *continuer,mini *s);
void initialiser_personange(personnage *p);



#endif //mini_h
