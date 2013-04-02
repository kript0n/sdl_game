#include "CSurface.h"
CSurface::CSurface() {

}


SDL_Surface* CSurface::OnLoad(char* file) {

    SDL_Surface* Temp_Surf;
    SDL_Surface* Return_Surf;

    if((Temp_Surf = IMG_Load(file)) == NULL) { //загружаем изображение
        return NULL;
    }

    Return_Surf = SDL_DisplayFormat(Temp_Surf); //возвращает поверхность соразмерную загруженному изображению во входную поверхность

    return Return_Surf;
}


bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y) {

    if( Surf_Dest == NULL || Surf_Src == NULL ) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR); //отображаем Surf_Src поверх Surf_Dest по координатам X,Y

    return true;

}


bool CSurface::OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H) {

    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }

    SDL_Rect DestR;

    DestR.x = X;
    DestR.y = Y;

    SDL_Rect SrcR;

    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;

    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);

    return true;
}

bool CSurface::Transparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    if(Surf_Dest == NULL) {
        return false;
    }

    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R,G,B));

    return true;
}
