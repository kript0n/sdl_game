#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class CSurface {

    public:

        CSurface();

        static SDL_Surface* OnLoad(char* file);                                         //загрузка изображения

        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y); //отображение поверхностей поверх друг друга

        static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);

        static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};



#endif
