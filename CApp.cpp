#include "CApp.h"
bool checkMusic = false;

CApp::CApp() {

    CurrentPlayer = 0;

    Surf_Display = NULL;

    Surf_Grid = NULL;

    Surf_X = NULL;

    Surf_O = NULL;

    Running = true;



}

int CApp::OnExecute() {                         //запуск

    if(!OnInit()) {                             //если не инициализировались
        throw "Can't init app";
    }

    SDL_Event Event;
    PlayMusic("GoodTheme.mp3", true);

    while(Running) {
        while(SDL_PollEvent(&Event)) {          //создаем очередь событий
            OnEvent(&Event);                    //обработка событий
        }

        OnLoop();

        OnRender();

        CheckWinner();
    }

    OnCleanup();

    return 0;
}

int main(int argc, char** argv) {
    try {

        CApp theApp;

        return theApp.OnExecute();

    }

    catch(const char* b) {

        std::ofstream log("log.txt");

        log << b;

        return 0;

    }
}

void CApp::Reset() {
    for(int i = 0; i < 9; i++) {
        Grid[i] = GRID_TYPE_NONE;
    }
    PlayMusic("WinBattle.mp3", false);
    PlayMusic("LoseCastle.mp3", false);
    PlayMusic("GoodTheme.mp3", true);
}

void CApp::SetCell(int ID, int TYPE) {
    if(ID < 0 || ID >= 9) return;

    if(TYPE < 0 || TYPE > GRID_TYPE_O) return;

    Grid[ID] = TYPE;
}

void CApp::PlayMusic(const char* name, bool turn) {

char path[256];
if(turn) {
    sprintf(path, "play ./music/%s", name);
}
else {
    sprintf(path, "stop ./music/%s", name);
}
mciSendString(path, NULL, NULL, NULL);

}
