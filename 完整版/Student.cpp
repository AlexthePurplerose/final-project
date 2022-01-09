//
//  Student.cpp
//  Final Project
//
//  Created by 盧家雯 on 2022/1/7.
//

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "LTexture.h"
#include "LWindow.h"
 
using namespace std ;
#include "Student.h"

void Student::freemedia_Student()
{
    //Free loaded images
    for ( int i = 0 ; i < 6 ; i++ ) {
        gKeyPressSurfaces[i].free() ;
    }
}


bool Student :: loadmedia_movement_player1 ()
{
    //Loading success flag
    bool success = true;

    //Load default surface
    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT1 ].loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/stu1.png" ))
    {
        printf( "Failed to load default1 image!\n" );
        success = false;
    }

    //Load A surface
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_D ].loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/raise1.png" ))
    {
        printf( "Failed to load D image!\n" ) ;
        success = false;
    }

    //Load D surface

    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_A ].loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/note.png" ))
    {
        printf( "Failed to load A image!\n" );
        success = false;
    }

    //Load left surface


    return success;
}

bool Student :: loadmedia_movement_player2 ()
{
    //Loading success flag
    bool success = true;

    //Load default surface

    // unchecked
    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT2 ].loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/stu2.png" ))
    {
        printf( "Failed to load default2 image!\n" );
        success = false;
    }


    //Load left surface

    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ].loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/note.png" ))
    {
        printf( "Failed to load left image!\n" );
        success = false;
    }

    //Load right surface

    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ].loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/raise2.png" ))
    {
        printf( "Failed to load right image!\n" );
        success = false;
    }

    return success;
}
