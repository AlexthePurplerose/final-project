//
//  player1.cpp
//  Final Project
//
//  Created by 盧家雯 on 2022/1/8.
//
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "LTexture.h"
#include "LWindow.h"
#include <SDL2/SDL.h>
#include "player1.h"
using namespace std;

player1::player1()
{
    ifcheat = false ;
    ifraise = false ;
}
void player1::setpos()
{
    pos_stu_x = 0.2562*gWindow.getWidth(); //student's position x
    pos_stu_y = 0.412*gWindow.getHeight(); //student's position y
    pos_note_x = 0.245*gWindow.getWidth(); //note's position x
    pos_note_y = 0.54*gWindow.getHeight() ; //note's position y
    //pos_raise_x=0.2565*gWindow.getWidth();
    //pos_raise_y=0.411*gWindow.getHeight();
}
void player1 :: handleEvent () {
    const Uint8 *state=SDL_GetKeyboardState(NULL);
    
    if(state[SDL_SCANCODE_A])
    {
        gKeyPressSurfaces[KEY_PRESS_SURFACE_D].free();
        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/stu1.png" );
        gKeyPressSurfaces[KEY_PRESS_SURFACE_A].loadFromFile("/Users/karen/Desktop/計算機程式/final-project/finalproject/note.png" );
        gKeyPressSurfaces[KEY_PRESS_SURFACE_A].render(pos_note_x,pos_note_y,NULL,-12,NULL,SDL_FLIP_NONE);
        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].render(pos_stu_x,pos_stu_y);
        ifcheat=1;
        ifraise=0;
    }
    else if(state[SDL_SCANCODE_D])
    {
        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].free();
        gKeyPressSurfaces[KEY_PRESS_SURFACE_A].free();
        gKeyPressSurfaces[KEY_PRESS_SURFACE_D].loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/raise1.png" );
        gKeyPressSurfaces[KEY_PRESS_SURFACE_D].render(pos_stu_x,pos_stu_y);
        ifraise=1;
        ifcheat=0;
    }
    else
    {
        gKeyPressSurfaces[KEY_PRESS_SURFACE_A].free();
        gKeyPressSurfaces[KEY_PRESS_SURFACE_D].free();
        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/stu1.png" );
        gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].render(pos_stu_x,pos_stu_y);
        ifraise=0;
        ifcheat=0;
    }
}
