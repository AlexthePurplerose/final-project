#include <stdio.h>
#include <string>
#include <sstream>
#include "LTexture.h"
#include "LWindow.h"
#include <SDL.h>
#include "player2.h"
player2::player2()
{
    pos_stu_x = 0 ; //student's position x
    pos_stu_y = 0 ; //student's position y
    pos_note_x = 0 ; //note's position x
    pos_note_y = 0 ; //note's position y
    ifcheat = false ;
    ifraise = false ;
}
void player2 :: handleEvent (SDL_Event& e ) {

    if (e.type == SDL_KEYDOWN) {
        //Select surfaces based on key press
        switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].loadFromFile("./student.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].loadFromFile("./note.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].render(pos_note_x, pos_note_y);
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].render(pos_stu_x, pos_stu_y);
                ifcheat = 1;
                ifraise = 0;
                break;
            case SDLK_RIGHT:
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].loadFromFile("./raise_hands.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].render(pos_stu_x, pos_stu_y);
                ifraise = 1;
                ifcheat = 0;
                break;
            default:
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].loadFromFile("./student.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].render(pos_stu_x, pos_stu_y);
                ifraise = 0;
                ifcheat = 0;
                break;
        }
    }
}
