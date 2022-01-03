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
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "LTexture.h"
#include "LWindow.h" 

using namespace std;
#include "Teacher.h"


//constructor: initialize variables
Teacher::Teacher(){
    pos_teach_x = 0; //teacher's position x
    pos_teach_y = 0; //teacher's position y
    pos_newp_x = 0; //newspaper's position x
    pos_newp_y = 0; //newspaper's position y
    read_newp = false; 
}

/*Teacher::~Teacher()
{
    //Deallocate
    free();
}*/ 

//The window renderer
//SDL_Renderer* gRenderer = NULL;

//LTexture
LTexture teacherTexture;
LTexture newspaperTexture;
LTexture teacherangryTexture;

bool Teacher::loadmedia_Teacher()
{
    //Loading success flag
    bool success = true;

    //Load teacher texture
    if( !teacherTexture.loadFromFile( "./teacher.png" ) )
    {
        printf( "Failed to load teacher texture image!\n" );
        success = false;
    }
    
    //Load newspaper texture
    if( !newspaperTexture.loadFromFile( "./newspaper.png" ) )
    {
        printf( "Failed to load newspaper texture image!\n" );
        success = false;
    }
    
    //Load teacher angry texture
    if( !teacherangryTexture.loadFromFile( "./angry.png" ) )
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

/*
bool Teacher::reading_newspaper()
{
    if (read_newp == true) return true;
    else return false;
}
 */

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
        bool quit = false;

        //Event handler
        SDL_Event e;
        
        unsigned int currenttime;
        unsigned int start = 0;
        
        bool flag = false;
        int rand_time1 = rand()%(10-3+1)+3;
        int rand_time2 = rand()%(10-3+1)+3;
        
        //While application is running
        while( !quit )
        {
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
            }

            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

            //Render teacher texture to screen
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
                newspaperTexture.render( pos_newp_x, pos_newp_y);
                read_newp = true;
            }
            
            //Update screen
            SDL_RenderPresent( gRenderer );
        }
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
        bool quit = false;

        //Event handler
        SDL_Event e;
        
        //While application is running
        while( !quit )
        {
            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
            }

            //Clear screen
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

            //Render teacher angry texture to screen
            teacherangryTexture.render( pos_teach_x, pos_teach_y);
            
            //Update screen
            SDL_RenderPresent( gRenderer );
        }
    }

}
