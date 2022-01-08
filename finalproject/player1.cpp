#include <stdio.h>
#include <string>
#include <sstream>
#include "LTexture.h"
#include "LWindow.h"
#include <SDL.h>
#include "player1.h"
player1::player1()
{
    ifcheat = false ;
    ifraise = false ;
}
void player1::setpos()//待定位
{
	pos_stu_x = 0.3*gWindow.getWidth(); //student's position x
    pos_stu_y = 0.4*gWindow.getHeight(); //student's position y
    pos_note_x = 0.3*gWindow.getWidth(); //note's position x
    pos_note_y = 0.55*gWindow.getHeight() ; //note's position y
    pos_raise_x=0.3*gWindow.getWidth();
    pos_raise_y=0.41*gWindow.getHeight();
}
void player1 :: handleEvent () {
	const Uint8 *state=SDL_GetKeyboardState(NULL);
                        if(state[SDL_SCANCODE_A])
                        {
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].loadFromFile( "./student.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].loadFromFile("./note.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].render(pos_note_x,pos_note_y);
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].render(pos_stu_x,pos_stu_y);
                            ifcheat=1;
                            ifraise=0;
                    	}
                        else if(state[SDL_SCANCODE_D])
                        {
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].loadFromFile( "./raise_hands.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].render(pos_raise_x,pos_raise_y);
                            ifraise=1;
                            ifcheat=0;
                    	}
                        else
                        {
                        	gKeyPressSurfaces[KEY_PRESS_SURFACE_A].free();
	                        gKeyPressSurfaces[KEY_PRESS_SURFACE_D].free();
	                        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].loadFromFile( "./student.png" );
	                        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].render(pos_stu_x,pos_stu_y);
	                        ifraise=0;
	                        ifcheat=0;
	                	}
}
