#include "CApp.h"

bool CApp::OnInit() {

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {                                                     //инициализируем все библиотеки sdl
        throw "Can't init SDL in CApp_OnItit.cpp line 10";
    }

    if((Surf_Display = SDL_SetVideoMode(600, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) { //создаем окно 640x480, 32 bits, используем аппаратное ускорение и двойной буфер
        throw "Can't set video mode in CApp_OnItit.cpp line 10";
    }

    if((Surf_Grid = CSurface::OnLoad("images/grid.bmp")) == NULL) {
        throw "Can't load surface";
    }

    if((Surf_X = CSurface::OnLoad("images/x.bmp")) == NULL) {
        throw "Can't load surface";
    }

    if((Surf_O = CSurface::OnLoad("images/o.bmp")) == NULL) {
        throw "Can't load surface";
    }

    CSurface::Transparent(Surf_X, 255,0,255);
    CSurface::Transparent(Surf_O, 255,0,255);

    Reset();

    return true;
}
