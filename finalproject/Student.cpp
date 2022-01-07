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
LTexture studentTexture;
LTexture noteTexture;
LTexture raisehandTexture;
Studnet::Student(){
    pos_stu_x = 0 ; //student's position x
    pos_stu_y = 0 ; //student's position y
    pos_stu_x = 0 ; //note's position x
    pos_note_y = 0 ; //note's position y
    ifcheat = false ;
    ifraise = false ;
}
bool Student::loadmedia_Student()
{
    //Loading success flag
    bool success = true;

    //Load student texture
    if( !studentTexture.loadFromFile( "/Users/user/Desktop/Final Picture" ) )
    {
        printf( "Failed to load student texture image!\n" );
        success = false;
    }

    //Load note texture
    if( !noteTexture.loadFromFile( "/Users/user/Desktop/Final Picture" ) )
    {
        printf( "Failed to load note texture image!\n" );
        success = false;
    }
    //Load student raisehand texture
    if ( !raisehandTexure.loadFromFile ( "/Users/user/Desktop/Final Picture" ) )
    {
        printf( "Failed to load raisehand texture image!\n" );
        success = false ;
    }

    return success;

}

//unchecked
void Student::freemedia_Student()
{
    //Free loaded images
    studentTexture.free();
    noteTexture.free();
    //studentangryTexture.free(); look !!
}

enum KeyPressSurfaces
{
    // unchecked
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_A,
    KEY_PRESS_SURFACE_D,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};
//SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
SDL_Surface* loadSurface( string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//The images that correspond to a keypress
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

bool loadMedia_movement ( int student )
{
    //Loading success flag
    bool success = true;

    //Load default surface

    // unchecked
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "/Users/user/Desktop/Final Picture" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    //Load A surface

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_A ] = loadSurface( "/Users/user/Desktop/Final Picture" ) ;
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_A ] == NULL )
    {
        printf( "Failed to load up image!\n" ) ;
        success = false;
    }

    //Load D surface

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_D ] = loadSurface( "/Users/user/Desktop/Final Picture" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_D ] == NULL )
    {
        printf( "Failed to load down image!\n" );
        success = false;
    }

    //Load left surface

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "/Users/user/Desktop/Final Picture" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
    {
        printf( "Failed to load left image!\n" );
        success = false;
    }

    //Load right surface

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "/Users/user/Desktop/Final Picture" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        printf( "Failed to load right image!\n" );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surfaces
    for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
    {
        SDL_FreeSurface( gKeyPressSurfaces[ i ] );
        gKeyPressSurfaces[ i ] = NULL;
    }

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
void Student :: movement ( int player , event e ) {

    // render student picture to screen
    studentTexture.render(pos_stu_x, pos_stu_y);
    // clear the screen
    if (!loadMedia()) {
        printf("Failed to load media!\n");
    } else {
        //Main loop flag
        bool quit = false;

        //Event handler
        SDL_Event e;

        //Set default current surface
        // not sure weather if I'm going to need it
        gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

        //While application is running
        while (!quit) {
            //Handle events on queue
            while (SDL_PollEvent(&e) != 0) {
                //User requests quit
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
                    //User presses a key
                else if (e.type == SDL_KEYDOWN) {
                    //Select surfaces based on key press
                    switch (e.key.keysym.sym) {
                        case SDLK_a:
                            freemedia_Student();
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_A];
                            break;

                        case SDLK_DOWN:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_D];
                            break;

                        case SDLK_LEFT:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
                            break;

                        case SDLK_RIGHT:
                            freemedia_Student();
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
                            break;

                        default:
                            gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
                            break;
                    }
                }
            }

            //Apply the current image
            SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);

            //Update the surface
            SDL_UpdateWindowSurface(gWindow);
        }
//    SDL_RenderCleaner( gRender ) ;
    }
    close() ;
}
/*void Student::raisehand()
{
    //Load media
    if( !loadmedia_Student() )
    {
        printf( "Failed to load media_student!\n" );
    }
    else
    {
        //Main loop flag
        pos_stu_x = 0.4501*gWindow.getWidth();
        pos_stu_y = 0.25427*gWindow.getHeight();
        pos_note_x = 0.418*gWindow.getWidth(); //student's position x
        pos_note_y = 0.332*gWindow.getHeight(); //student's position y


        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );

        //Render teacher texture to screen
        studentTexture.render( pos_stu_x, pos_stu_y);

//        currenttime = SDL_GetTicks();

//        if (currenttime - start < rand_time1*1000)
//        {
//            flag = false; //沒有報紙
//        }// 我不用
//        else if ( currenttime - start > rand_time1*1000 &&
//                  currenttime - start < ( rand_time1+rand_time2 ) * 1000 )
//        {
//            flag = true; //有報紙
//            read_newp = true;
//            int rand_shake = rand()%(1-0+1)+0; //隨機變數決定要不要抖報紙
//
//            if (currenttime - start > (rand_time1+rand_time2)*1000-1000) //看完報紙前一秒一定要抖報紙
//            {
//                if (currenttime%2 == 0) newspaperTexture.render( pos_newp_x, pos_newp_y);
//                else newspaperTexture.render(pos_newp_x, pos_newp_y,NULL,-10,NULL,SDL_FLIP_NONE);
//            }
//            else
//            {
//                if (rand_shake == 0) newspaperTexture.render( pos_newp_x, pos_newp_y); //不抖報紙
//                else { //抖報紙
//                    if (currenttime%2 == 0) newspaperTexture.render( pos_newp_x, pos_newp_y);
//                    else newspaperTexture.render(pos_newp_x, pos_newp_y,NULL,-10,NULL,SDL_FLIP_NONE);
//                }
//            }
//        }
//        else
//        {
//            start = currenttime;
//            rand_time1 = rand()%(10-3+1)+1;
//            rand_time2 = rand()%(10-3+1)+1;
//        }

        /*
        if (flag == true && currenttime%2 == 0)
        {
            pos_newp_x = 0.418*gWindow.getWidth(); //newspaper's position x
            pos_newp_y = 0.332*gWindow.getHeight(); //newspaper's position y
            newspaperTexture.render( pos_newp_x, pos_newp_y);
            read_newp = true;
        }
        else if (flag == true && currenttime%2 == 1)
        {
            pos_newp_x = 0.418*gWindow.getWidth(); //newspaper's position x
            pos_newp_y = 0.332*gWindow.getHeight(); //newspaper's position y
            newspaperTexture.render(pos_newp_x, pos_newp_y,NULL,-10,NULL,SDL_FLIP_NONE );
            read_newp = true;
        }
         */

        //Update screen
        //SDL_RenderPresent( gRenderer );




    //Free resources and close SDL
    //freemedia_Teacher();


    /*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, standard IO, and strings
