#include <stdio.h>
#include <string>
#include <sstream>
#include "LTexture.h"
#include "LWindow.h"
#include <SDL.h>
#include "player1.h"
player1::player1()
{
    pos_stu_x = 0 ; //student's position x
    pos_stu_y = 0 ; //student's position y
    pos_note_x = 0 ; //note's position x
    pos_note_y = 0 ; //note's position y
    ifcheat = false ;
    ifraise = false ;
}
void player1 :: handleEvent ( SDL_Event& e ) {
	
                if (e.type == SDL_KEYDOWN) {
                    //Select surfaces based on key press
                    switch (e.key.keysym.sym) {
                        case SDLK_a:
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].loadFromFile( "./student.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].loadFromFile("./note.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].render(pos_note_x,pos_note_y);
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].render(pos_stu_x, pos_stu_y);
                            ifcheat=1;
                            ifraise=0;
                            break;
                        case SDLK_d:
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].loadFromFile( "./raise_hands.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].render(pos_stu_x,pos_stu_y);
                            ifraise=1;
                            ifcheat=0;
                            break;
                        default:
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].loadFromFile( "./student.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].render(pos_stu_x, pos_stu_y);
                            ifraise=0;
                            ifcheat=0;
                            break;
                    }
                }
}
