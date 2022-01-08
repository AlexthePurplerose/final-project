#include <stdio.h>
#include <string>
#include <sstream>
#include "LTexture.h"
#include "LWindow.h"
#include <SDL.h>
#include "player2.h"
player2::player2()
{
    ifcheat = false ;
    ifraise = false ;
}
void player2::setpos()//待定位
{
	pos_stu_x = 0.55*gWindow.getWidth(); //student's position x
    pos_stu_y = 0.4*gWindow.getHeight(); //student's position y
    pos_note_x = 0.55*gWindow.getWidth(); //note's position x
    pos_note_y = 0.55*gWindow.getHeight() ; //note's position y
    pos_raise_x=0.55*gWindow.getWidth();
    pos_raise_y=0.41*gWindow.getHeight();
}
void player2 :: handleEvent () {
	const Uint8 *state=SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_LEFT])
            {
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].loadFromFile("./student.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].loadFromFile("./note.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].render(pos_note_x, pos_note_y);
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].render(pos_stu_x, pos_stu_y);
                ifcheat = 1;
                ifraise = 0;
        	}
            else if(state[SDL_SCANCODE_RIGHT])
            {
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].loadFromFile("./raise_hands.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].render(pos_raise_x, pos_raise_y);
                ifraise = 1;
                ifcheat = 0;
        	}
            else
            {
            	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].free();
		    	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].free();
		        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].loadFromFile("./student.png");
		        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].render(pos_stu_x, pos_stu_y);
		        ifraise = 0;
		        ifcheat = 0;
        	}
}
