//
//  player2.cpp
//  Final Project
//
//  Created by 盧家雯 on 2022/1/8.
//

#include <stdio.h>
#include <string>
#include <sstream>
#include "LTexture.h"
#include "LWindow.h"
#include <SDL2/SDL.h>
#include "player2.h"

player2::player2()
{
    ifcheat = false ;
    ifraise = false ;
}
void player2::setpos()
{
    pos_stu_x = 0.503*gWindow.getWidth(); //student's position x
    pos_stu_y = 0.41*gWindow.getHeight(); //student's position y
    pos_note_x = 0.614*gWindow.getWidth(); //note's position x
    pos_note_y = 0.549*gWindow.getHeight() ; //note's position y
    //pos_raise_x=0.55*gWindow.getWidth();
    //pos_raise_y=0.41*gWindow.getHeight();
}
void player2 :: handleEvent () {
    const Uint8 *state=SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_LEFT])
    {
        gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].free();
        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].loadFromFile("/Users/karen/Desktop/計算機程式/final-project/finalproject/stu2.png");
        gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].loadFromFile("/Users/karen/Desktop/計算機程式/final-project/finalproject/note.png");
        gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].render(pos_note_x, pos_note_y,NULL,20,NULL,SDL_FLIP_NONE);
        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].render(pos_stu_x, pos_stu_y);
        ifcheat = 1;
        ifraise = 0;
    }
    else if(state[SDL_SCANCODE_RIGHT])
    {
        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].free();
        gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].free();
        gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].loadFromFile("/Users/karen/Desktop/計算機程式/final-project/finalproject/raise2.png");
        gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].render(pos_stu_x, pos_stu_y);
        ifraise = 1;
        ifcheat = 0;
    }
    else
    {
        gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].free();
        gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].free();
        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].loadFromFile("/Users/karen/Desktop/計算機程式/final-project/finalproject/stu2.png");
        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].render(pos_stu_x, pos_stu_y);
        ifraise = 0;
        ifcheat = 0;
    }
}
