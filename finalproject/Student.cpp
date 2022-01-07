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
player1::player1(){
    pos_stu_x = 0 ; //student's position x
    pos_stu_y = 0 ; //student's position y
    pos_note_x = 0 ; //note's position x
    pos_note_y = 0 ; //note's position y
    ifcheat = false ;
    ifraise = false ;
}
player2::player2()
{
    pos_stu_x = 0 ; //student's position x
    pos_stu_y = 0 ; //student's position y
    pos_note_x = 0 ; //note's position x
    pos_note_y = 0 ; //note's position y
    ifcheat = false ;
    ifraise = false ;
}
//unchecked
void Student::freemedia_Student()
{
    //Free loaded images
    for ( int i = 0 ; i < 5 ; i++ ) {
        gKeyPressSurfaces[i].free() ;
    }
//    studentTexture.free();
//    noteTexture.free();
//    raisehandTexture.free();
    //studentangryTexture.free(); look !!
}

enum KeyPressSurfaces
{
    // unchecked
    KEY_PRESS_SURFACE_DEFAULT1,
    KEY_PRESS_SURFACE_DEFAULT2,
    KEY_PRESS_SURFACE_A,
    KEY_PRESS_SURFACE_D,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT
};
//SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ]

//The window we'll be rendering to

//The surface contained by the window

//The images that correspond to a keypress

//The images that correspond to a keypress

//Current displayed image

//測試按件
bool Student :: loadMedia_movement_player1 ()
{
    //Loading success flag
    bool success = true;

    //Load default surface

    // unchecked
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT1 ] = loadFromFile( "/Users/user/Desktop/Final Picture/Student.png" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    //Load A surface

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_D ] = loadFromFile( "/Users/user/Desktop/Final Picture/raise_hands.png" ) ;
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_D ] == NULL )
    {
        printf( "Failed to load up image!\n" ) ;
        success = false;
    }

    //Load D surface

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_A ] = loadFromFile( "/Users/user/Desktop/Final Picture/note.png" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_A ] == NULL )
    {
        printf( "Failed to load down image!\n" );
        success = false;
    }

    //Load left surface


    return success;
}

bool Student :: loadMedia_movement_player2 ()
{
    //Loading success flag
    bool success = true;

    //Load default surface

    // unchecked
    gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT2 ] = loadFromFile( "/Users/user/Desktop/Final Picture/Student.png" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
    {
        printf( "Failed to load default image!\n" );
        success = false;
    }

    //Load A surface


    //Load left surface

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadFromFile( "/Users/user/Desktop/Final Picture/note.png" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
    {
        printf( "Failed to load left image!\n" );
        success = false;
    }

    //Load right surface

    gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadFromFile( "/Users/user/Desktop/Final Picture/raise_hands.png" );
    if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
    {
        printf( "Failed to load right image!\n" );
        success = false;
    }

    return success;
}

void player1 :: handleEvent ( SDL_Event& e ) {

        //Set default current surface
        // not sure weather if I'm going to need i

        //While application is runni
                    //User presses a key
                if (e.type == SDL_KEYDOWN) {
                    //Select surfaces based on key press
                    switch (e.key.keysym.sym) {
                        case SDLK_a:
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].loadFromFile( "/Users/user/Desktop/Final Picture/Student.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].loadFromFile("/Users/user/Desktop/Final Picture/note.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].render(pos_note_x,pos_note_y);
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].render(pos_stu_x, pos_stu_y);
                            ifcheat=1;
                            ifraise=0;
                            break;
                        case SDLK_d:
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].loadFromFile( "/Users/user/Desktop/Final Picture/raise_hands.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].render(pos_stu_x,pos_stu_y);
                            ifraise=1;
                            ifcheat=0;
                            break;
                        default:
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_A].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_D].free();
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].loadFromFile( "/Users/user/Desktop/Final Picture/Student.png" );
                            gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].render(pos_stu_x, pos_stu_y);
                            ifraise=0;
                            ifcheat=0;
                            break;
                    }
                }
}
void player2 :: handleEvent ( int player , event e ) {

    if (e.type == SDL_KEYDOWN) {
        //Select surfaces based on key press
        switch (e.key.keysym.sym) {
            case SDLK_LEFT:
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].loadFromFile(
                        "/Users/user/Desktop/Final Picture/Student.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].loadFromFile("/Users/user/Desktop/Final Picture/note.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].render(pos_note_x, pos_note_y);
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT1].render(pos_stu_x, pos_stu_y);
                ifcheat = 1;
                ifraise = 0;
                break;
            case SDLK_RIGHT:
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].loadFromFile(
                        "/Users/user/Desktop/Final Picture/raise_hands.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].render(pos_stu_x, pos_stu_y);
                ifraise = 1;
                ifcheat = 0;
                break;
            default:
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT].free();
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].loadFromFile(
                        "/Users/user/Desktop/Final Picture/Student.png");
                gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT2].render(pos_stu_x, pos_stu_y);
                ifraise = 0;
                ifcheat = 0;
                break;
        }
    }
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
