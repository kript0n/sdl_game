#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL/SDL.h>
#include <fstream>
#include <windows.h>

#include "surface/CSurface.h"
#include "Events/CEvent.h"
//DWORD WINAPI WaitData ( LPVOID data );


class CApp : public CEvent {

    //friend DWORD WINAPI WaitData( LPVOID data );

    private:

        void PlayMusic(const char* name, bool turn);

        int CurrentPlayer;

        bool Running;

        SDL_Surface* Surf_Display;

        SDL_Surface* Surf_Grid;

        SDL_Surface* Surf_X;

        SDL_Surface* Surf_O;

        int Grid[9];

        DWORD threadID;

        enum {
            GRID_TYPE_NONE = 0,
            GRID_TYPE_X,
            GRID_TYPE_O
        };


    public:

        CApp();

        int OnExecute();

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnLButtonDown(int mX, int My);

        void OnRender();

        void OnLoop();

        void OnExit();

        void OnCleanup();

        void Reset();

        void SetCell(int ID, int TYPE);

        void CheckWinner();

        void WMessage(int player);

        static bool thd;

};

/*DWORD WINAPI WaitData ( LPVOID data ) {
    CNet::Start_Wsa();
    char Multiplayer_Data[1];
    while(recv(CNet::Connect_Socket, Multiplayer_Data, sizeof(Multiplayer_Data), 0)) {
        if(CEvent::CurrentPlayer == 1) {
            std::string integer = Multiplayer_Data;
            int id = atoi(integer.c_str());
            CApp::SetCell(id, CApp::GRID_TYPE_O);
            CEvent::CurrentPlayer = 0;
        }
    }
}*/

#endif
