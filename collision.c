#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "collision.h"
/**
Uint32 GetPixel(SDL_Surface *pSurface, int x, int y)

 bech te5ou les adress mta3 les pixels  

 x heya X mta3 el pixel ili 7achetna biha

y heya Y mta3 el pixel ili 7achetna biha



p l'adresse mta3 el pixel 

*/

Uint32 GetPixel(SDL_Surface *pSurface, int x, int y)
{
        int bpp = pSurface->format->BytesPerPixel;
        
        Uint8 *p = (Uint8 *)pSurface->pixels + y * pSurface->pitch + x * bpp;
     
        switch(bpp) 
                    {
        case 1:
      return *p;
      break;
     
        case 2:
      return *(Uint16 *)p;
      break;
     
        case 3:
      if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
          return p[0] << 16 | p[1] << 8 | p[2];
      else
          return p[0] | p[1] << 8 | p[2] << 16;
      break;
     
        case 4:
      return *(Uint32 *)p;
      break;
     
        default:
      return 0;       /* s3ib ken tsir ama bech neb3dou 3ala les erreurs */
        }
}

/**
 int collision(SDL_Surface *mask,int x,int y,int height)

 bech detecti el collision fil mask 

x heya X mta3 el joueur (el personnage)

y heya Y mta3 el joueur (el personnage)

height how toul mta3 el personnage

0 ken mafamech collision , 1 ken fama collision m3a el background (ma3eha el mask ps:mayodhorech betbi3a)

*/


/**
     int pixel_test(SDL_Surface *surface,int x,int y)

bech tal9a el couleur ili tsir m3ah el collision 

x heya X mta3 el pixel ili 7achetna biha

y heya Y mta3 el pixel ili 7achetna biha




0 ken el couleur (0,0,0)(ps:ena 7atou noir fil mask ) and 1 ken el couleur mo5talef 3ala noir

*/


   int collision(SDL_Surface *mask,int x,int y,int height)
   {
      int i;
      Uint8 r,g,b;
      for(i=y;i<=y+height-10;i++)
      {
        SDL_GetRGB(GetPixel(mask,x,i),mask->format,&r,&g,&b);
        if(r==0 && g==0 && b==0) break;
      }

      if(i<=y+height-10) return 0;
      else return 1;
   }

   int pixel_test(SDL_Surface *surface,int x,int y)
   {
      Uint8 r,g,b;
      SDL_GetRGB(GetPixel(surface,x,y),surface->format,&r,&g,&b);
      if(r==0 && g==0 && b==0)
      {
        return 0;
      }
      else 
      {
        return 1;
      }
   }



