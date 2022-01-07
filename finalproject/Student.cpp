#include <stdio.h>
#include <string>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "LTexture.h"
#include "LWindow.h"
#include "Student.h"
void Student::freemedia_Student()
{
    //Free loaded images
    for ( int i = 0 ; i < 6 ; i++ ) {
        gKeyPressSurfaces[i].free() ;
    }
}

//測試按件
bool Student :: loadmedia_movement_player1 ()
{
    //Loading success flag
    bool success = true;

    //Load default surface

    // unchecked
    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT1 ].loadFromFile( "./student.png" ))
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    //Load A surface

    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_D ].loadFromFile( "./raise_hands.png" ))
    {
        printf( "Failed to load up image!\n" ) ;
        success = false;
    }

    //Load D surface

    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_A ].loadFromFile( "./note.png" ))
    {
        printf( "Failed to load down image!\n" );
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
    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT2 ].loadFromFile( "./student.png" ))
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    //Load A surface


    //Load left surface

    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ].loadFromFile( "./note.png" ))
    {
        printf( "Failed to load left image!\n" );
        success = false;
    }

    //Load right surface

    
    if(!gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ].loadFromFile( "./raise_hands.png" ))
    {
        printf( "Failed to load right image!\n" );
        success = false;
    }

    return success;
}
