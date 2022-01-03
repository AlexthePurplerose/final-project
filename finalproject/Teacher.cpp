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
#include <time.h>
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
        pos_teach_x = 0.4501*gWindow.getWidth(); //teacher's position x
        pos_teach_y = 0.25427*gWindow.getHeight(); // teacher's position y
        pos_newp_x = 0.418*gWindow.getWidth(); //newspaper's position x
        pos_newp_y = 0.332*gWindow.getHeight(); //newspaper's position y
        
        
        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        //SDL_RenderClear( gRenderer );

        //Render teacher texture to screen
        teacherTexture.render( pos_teach_x, pos_teach_y);
        
        Uint32 current = SDL_GetTicks();
        
        //Set the seed and generate random number from 3s to 10s
        srand((unsigned)time(NULL));
        static int rand_time1 = rand()%(10-3+1)+3; //不看報紙的秒數
        static int rand_time2 = rand()%(10-3+1)+3; //看報紙的秒數
        
        cout << "No: " << rand_time1 << endl;
        cout << "Yes: " << rand_time2 << endl;
        
        if (current - start <= rand_time1*1000)//沒看報紙
        {
            read_newp = false;
        }
        else if (current - start > rand_time1*1000 && //看報紙
                 current - start < (rand_time1+rand_time2)*1000)
        {
            read_newp = true;
            int rand_shake = rand()%(1-0+1)+0; //決定要不要抖報紙，產生0或1
            
            if (current - start > (rand_time1+rand_time2)*1000-1000) //看完報紙前一秒一定要抖報紙
            {
                //根據目前時間是否為偶數來改變報紙角度
                if (current%2 == 0) newspaperTexture.render( pos_newp_x, pos_newp_y);
                else newspaperTexture.render(pos_newp_x, pos_newp_y,NULL,-10,NULL,SDL_FLIP_NONE);
            }
            else
            {
                if (rand_shake == 0) newspaperTexture.render( pos_newp_x, pos_newp_y); //不抖報紙
                else { //抖報紙
                    if (current%2 == 0) newspaperTexture.render( pos_newp_x, pos_newp_y);
                    else newspaperTexture.render(pos_newp_x, pos_newp_y,NULL,-10,NULL,SDL_FLIP_NONE);
                }
            }
        }
        else
        {
            //超過一輪看跟不看報紙的時間，更新start
            start = current;
            rand_time1 = rand()%(10-3+1)+3;
            rand_time2 = rand()%(10-3+1)+3;
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
        printf( "Failed to load media_teacher_angry!\n" );
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
        //SDL_RenderPresent( gRenderer );
            
    }

}
