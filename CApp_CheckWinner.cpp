#include "CApp.h"

void CApp::WMessage(int player) {
    PlayMusic("GoodTheme.mp3", false);
    HWND hWnd = FindWindow(NULL, "SDL_app");
    switch ( player ) {

        case 1: {
            PlayMusic("WinBattle.mp3", true);
            if((MessageBox(hWnd, "Player 1 win! Reset?", "Result", MB_YESNO)) == IDYES) Reset();
            else Running = false;
            break;
        }

        case 2: {
            PlayMusic("WinBattle.mp3", true);
            if((MessageBox(hWnd, "Player 2 win! Reset?", "Result", MB_YESNO)) == IDYES) Reset();
            else Running = false;
            break;
        }

        case 3: {
            PlayMusic("LoseCastle.mp3", false);
            if((MessageBox(hWnd, "Sorry, but there is no winner! Reset?", "Result", MB_YESNO)) == IDYES) Reset();
            else Running = false;
            break;
        }
    }
    return;
}

void CApp::CheckWinner() {
    int part1[3] = {Grid[0], Grid[1], Grid[2]};
    int part2[3] = {Grid[3], Grid[4], Grid[5]};
    int part3[3] = {Grid[6], Grid[7], Grid[8]};


//======================================DIAGONAL LEFT-TOP========================================//
    if(part1[0] == GRID_TYPE_X && part2[1] == GRID_TYPE_X && part3[2] == GRID_TYPE_X) {
        WMessage(1);
        return;
    }
    else if(part1[0] == GRID_TYPE_O && part2[1] == GRID_TYPE_O && part3[2] == GRID_TYPE_O) {
        WMessage(2);
        return;
    }
//===============================================================================================//



//========================================DIAGONAL RIGHT-TOP=====================================//
    if(part1[2] == GRID_TYPE_X && part2[1] == GRID_TYPE_X && part3[0] == GRID_TYPE_X) {
        WMessage(1);
        return;
    }
    else if(part1[2] == GRID_TYPE_O && part2[1] == GRID_TYPE_O && part3[0] == GRID_TYPE_O) {
        WMessage(2);
        return;
    }
//================================================================================================//



//==================================================HORIZONTAL========================================//
    if(part1[0] == GRID_TYPE_X && part1[1] == GRID_TYPE_X && part1[2] == GRID_TYPE_X) {
        WMessage(1);
        return;
    }
    else if(part1[0] == GRID_TYPE_O && part1[1] == GRID_TYPE_O && part1[2] == GRID_TYPE_O) {
        WMessage(2);
        return;
    }

    if(part2[0] == GRID_TYPE_X && part2[1] == GRID_TYPE_X && part2[2] == GRID_TYPE_X) {
        WMessage(1);
        return;
    }
    else if(part2[0] == GRID_TYPE_O && part2[1] == GRID_TYPE_O && part2[2] == GRID_TYPE_O) {
        WMessage(2);
        return;
    }

    if(part3[0] == GRID_TYPE_X && part3[1] == GRID_TYPE_X && part3[2] == GRID_TYPE_X) {
        WMessage(1);
        return;
    }
    else if(part3[0] == GRID_TYPE_O && part3[1] == GRID_TYPE_O && part3[2] == GRID_TYPE_O) {
        WMessage(2);
        return;
    }

//====================================HORIZONTAL END=======================================//


    bool End = true;
    for(int i = 0; i < 3; i++) {
//======================================check for the end===========================================//
        if(part1[i] == GRID_TYPE_NONE || part2[i] == GRID_TYPE_NONE || part3[i] == GRID_TYPE_NONE) {
            End = false;
        }
//==================================================================================================//

//=======================================VERTICAL===================================================//
        if(part1[i] == GRID_TYPE_X && part2[i] == GRID_TYPE_X && part3[i] == GRID_TYPE_X) {
            WMessage(1);
            return;
        }
        else if(part1[i] == GRID_TYPE_O && part2[i] == GRID_TYPE_O && part3[i] == GRID_TYPE_O) {
            WMessage(2);
            return;
        }
//===================================================================================================//
    }

    if(End) {
        WMessage(3);
    }
}
