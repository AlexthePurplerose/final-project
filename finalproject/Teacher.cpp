//
//  Teacher.cpp
//  Final Project
//
//  Created by 盧家雯 on 2022/1/1.
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

using namespace std;
#include "Teacher.h"

//LTexture
LTexture teacherTexture;
LTexture newspaperTexture;
LTexture teacherangryTexture;

//constructor: initialize variables
Teacher::Teacher(){
    pos_teach_x = 0; //teacher's position x
    pos_teach_y = 0; //teacher's position y
    pos_newp_x = 0; //newspaper's position x
    pos_newp_y = 0; //newspaper's position y
    start = 0;
    read_newp = false;
}

/*Teacher::~Teacher()
{
    //Deallocate
    free();
}*/

//The window renderer
//SDL_Renderer* gRenderer = NULL;

bool Teacher::loadmedia_Teacher()
{
    //Loading success flag
    bool success = true;

    //Load teacher texture
    if( !teacherTexture.loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/teacher.png" ) )
    {
        printf( "Failed to load teacher texture image!\n" );
        success = false;
    }
    
    //Load newspaper texture
    if( !newspaperTexture.loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/newspaper.png" ) )
    {
        printf( "Failed to load newspaper texture image!\n" );
        success = false;
    }
    
    //Load teacher angry texture
    if( !teacherangryTexture.loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/angry.png" ) )
    {
        printf( "Failed to load teacher angry texture image!\n" );
        success = false;
    }

    return success;
}

void Teacher::freemedia_Teacher()
{
    //Free loaded images
    teacherTexture.free();
    newspaperTexture.free();
    teacherangryTexture.free();
}


void Teacher::action()
{
    //Load media
    if( !loadmedia_Teacher() )
    {
        printf( "Failed to load media_teacher!\n" );
    }
    else
    {
        //Main loop flag
        
        unsigned int currenttime;
        //unsigned int start = 0;
        
        bool flag = false;
        static int rand_time1 = rand()%(10-3+1)+3;
        static int rand_time2 = rand()%(10-3+1)+3;
        
        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        //SDL_RenderClear( gRenderer );

        //Render teacher texture to screen
        pos_teach_x = 0.4501*gWindow.getWidth();
        pos_teach_y = 0.25427*gWindow.getHeight();
        teacherTexture.render( pos_teach_x, pos_teach_y);
        
        currenttime = SDL_GetTicks();
        
        if (currenttime - start < rand_time1*1000)
        {
            flag = false; //沒有報紙
        }
        else if (currenttime - start > rand_time1*1000 &&
                 currenttime - start < (rand_time1+rand_time2)*1000)
        {
            flag = true; //有報紙
        }
        else
        {
            start = currenttime;
            rand_time1 = rand()%(10-3+1)+1;
            rand_time2 = rand()%(10-3+1)+1;
        }
        
        if (flag == true)
        {
            pos_newp_x = 0.418*gWindow.getWidth(); //newspaper's position x
            pos_newp_y = 0.332*gWindow.getHeight(); //newspaper's position y
            newspaperTexture.render( pos_newp_x, pos_newp_y);
            read_newp = true;
        }
        
        //Update screen
        //SDL_RenderPresent( gRenderer );

            
    }

    //Free resources and close SDL
    //freemedia_Teacher();

}

void Teacher::angry()
{
    if( !loadmedia_Teacher() )
    {
        printf( "Failed to load media_teacher!\n" );
    }
    else
    {
        //Main loop flag
        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );

        //Render teacher angry texture to screen
        teacherangryTexture.render( pos_teach_x, pos_teach_y);
        
        //Update screen
        SDL_RenderPresent( gRenderer );
            
    }

}
