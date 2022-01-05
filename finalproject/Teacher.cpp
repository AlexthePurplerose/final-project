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
LTexture newspaper2Texture;
LTexture newspaper3Texture;
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
/*
Teacher::~Teacher()
{
    //Deallocate
    free();
}
 */

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
    
    //Load newspaper2 texture
    if( !newspaper2Texture.loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/newspaper2.png" ) )
    {
        printf( "Failed to load newspaper2 texture image!\n" );
        success = false;
    }
    
    //Load newspaper3 texture
    if( !newspaper3Texture.loadFromFile( "/Users/karen/Desktop/計算機程式/final-project/finalproject/newspaper3.png" ) )
    {
        printf( "Failed to load newspaper3 texture image!\n" );
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
    newspaper2Texture.free();
    newspaper3Texture.free();
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
        //Set the images; position
        pos_teach_x = 0.45*gWindow.getWidth(); //teacher's position x
        pos_teach_y = 0.25427*gWindow.getHeight(); // teacher's position y
        pos_newp_x = 0.418*gWindow.getWidth(); //newspaper's position x
        pos_newp_y = 0.325*gWindow.getHeight(); //newspaper's position y
        
        
        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

        // Show teacher
        teacherTexture.render( pos_teach_x, pos_teach_y);
        //newspaper2Texture.render(0.439*gWindow.getWidth() , 0.408*gWindow.getHeight());
        //newspaper3Texture.render(0.439*gWindow.getWidth() , 0.385*gWindow.getHeight());
        
        
        Uint32 current = SDL_GetTicks();
        int rand_shake;
        
        //Set the seed and generate random number from 3s to 10s
        srand(current);
        static int rand_time1 = rand()%(6-3+1)+3; //不看報紙的總秒數
        static int rand_time2 = rand()%(10-3+1)+3; //看報紙的總秒數
        
        if (current - start <= rand_time1*1000)//沒看報紙
        {
            read_newp = false;
            newspaper2Texture.render(0.439*gWindow.getWidth(), 0.408*gWindow.getHeight()); //沒在看報紙的“報紙”
        }
        else if (current - start > rand_time1*1000 && //看報紙
                 current - start < (rand_time1+rand_time2)*1000)
        {
            read_newp = true;
            srand((unsigned)time(NULL));
            rand_shake = rand()%(3-0+1)+0; //決定要不要抖報紙，產生0~3的隨機變數
            
            if (rand_shake == 1) {
                //newspaper3Texture.render(0.44*gWindow.getWidth() , 0.348*gWindow.getHeight());
                newspaperTexture.render( pos_newp_x, 0.34*gWindow.getHeight());
            }
            else {
                newspaperTexture.render( pos_newp_x, pos_newp_y);
            }
        }
        else //看報紙與不看的過渡期(快看完，還在看)
        {
            read_newp = true;
            //newspaper3Texture.render(0.44*gWindow.getWidth(), 0.35*gWindow.getHeight());
            newspaperTexture.render( pos_newp_x, 0.345*gWindow.getHeight());
            
            //超過一輪看跟不看報紙的時間，更新start
            start = current;
            rand_time1 = rand()%(6-3+1)+3;
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
