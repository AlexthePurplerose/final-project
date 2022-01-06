#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "LTexture.h"
#include "LWindow.h"
#include "LButton.h"
#include "Tiempo.h"
#include "Teacher.h"

enum scenario{
    starting=0,
    ruleintro=1,
    playing=2,
    betweenrounds=3,
    finish=4
};
SDL_Renderer* gRenderer=NULL;
const int SCREEN_WIDTH=640;
const int SCREEN_HEIGHT=480;
LWindow gWindow;
TTF_Font *gFont = NULL;
TTF_Font *bigFont = NULL;
SDL_Color white={255,255,255};
SDL_Color yellow={255,255,0};
SDL_Color purple={221,160,221};
LTexture test;
LTexture gSceneTexture;
LTexture StartTexture;
LTexture RuleTexture;
LTexture BackTexture;
LTexture Shijian;
LTexture Gameover;
LTexture p1word;
LTexture p2word;
Tiempo countdown;
Teacher teacher;
LButton Start(318,92);
LButton Rule(336,111);
LButton Back(198,113);
bool ruleon, starton, backon;
bool init()
{
    bool success = true;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        if( !gWindow.init() )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            gRenderer = gWindow.createRenderer();
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
            }
        }
    }
    countdown.reset();
    return success;
}
bool loadMedia()
{
    bool success = true;
    if( !test.loadFromFile( "./gamestart.png" ) )
    {
        printf( "Failed to load window texture!\n" );
        success = false;
    }
    if( !test.loadFromFile( "./gamestartbutton.png" ) )
    {
        printf( "Failed to load buttons texture!\n" );
        success = false;
    }
    if(!test.loadFromFile( "./rulebutton.png" ) )
    {
        printf( "Failed to load buttons texture!\n" );
        success = false;
    }
    if(!test.loadFromFile("./rule.png"))
    {
        printf( "Failed to load rule texture!\n" );
        success = false;
    }
    if(!test.loadFromFile("./backbutton.png"))
    {
        printf( "Failed to load buttons texture!\n" );
        success = false;
    }
    if(!test.loadFromFile("./playing.png"))
    {
        printf( "Failed to load window texture!\n" );
        success = false;
    }
    gFont = TTF_OpenFont( "./eltipodeletrausado.ttf", 60 );
    if( gFont == NULL )
    {
        printf( "Failed to load eltipodeletrausado font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    bigFont = TTF_OpenFont( "./eltipodeletrausado.ttf", 200 );
    if( bigFont == NULL )
    {
        printf( "Failed to load eltipodeletrausado font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    TTF_SetFontStyle(bigFont, TTF_STYLE_BOLD);
    if(!test.loadFromRenderedText("test",white,gFont))
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if(!test.loadFromRenderedText("test",white,bigFont))
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if(!teacher.loadmedia_Teacher())
    {
        printf("Failed to load Teacher!\n");
        success=false;
    }
    test.free();
    return success;
}

void putMedia(scenario s)
{
    switch(s)
    {
        case starting:
            gSceneTexture.free();
            BackTexture.free();
            Shijian.free();
            teacher.freemedia_Teacher();
            countdown.free();
            gSceneTexture.loadTexture("./gamestart.png");
            if(!starton) StartTexture.loadFromFile("./gamestartbutton.png");
            else StartTexture.loadTexture2("./gamestartbutton.png",101,349);
            if(!ruleon) RuleTexture.loadFromFile("./rulebutton.png");
			else RuleTexture.loadTexture2("./rulebutton.png",122,369);
            gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2);
            StartTexture.render(gWindow.getWidth()*2/5, gWindow.getHeight()*3/5,NULL,-10,NULL,SDL_FLIP_NONE );
			RuleTexture.render( gWindow.getWidth()*7/17, gWindow.getHeight()*21/30,NULL,-10,NULL,SDL_FLIP_NONE );
			Start.work=1;
            Rule.work=1;
            Back.work=0;
            Back.mCurrentSprite=BUTTON_SPRITE_MOUSE_OUT;
            break;
        case ruleintro:
            gSceneTexture.free();
            StartTexture.free();
            RuleTexture.free();
            Shijian.free();
            countdown.free();
            teacher.freemedia_Teacher();
            gSceneTexture.loadTexture("./rule.png");
            if(!backon) BackTexture.loadFromFile("./backbutton.png");
            else BackTexture.loadTexture2("./backbutton.png",124,218);
            gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2 );
            BackTexture.render(gWindow.getWidth()*4/9, gWindow.getHeight()*8/9);
            Start.work=0;
            Start.mCurrentSprite=BUTTON_SPRITE_MOUSE_OUT;
            Rule.work=0;
            Rule.mCurrentSprite=BUTTON_SPRITE_MOUSE_OUT;
            Back.work=1;
            break;
        case playing:
            gSceneTexture.free();
            StartTexture.free();
            RuleTexture.free();
            BackTexture.free();
            gSceneTexture.loadTexture("./playing.png");
            Shijian.loadFromRenderedText("Time: ",white, gFont);
            countdown.loadFromRenderedText(countdown.tout.str(),white,gFont);
            gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2 );
            teacher.action(); //teacher
            Shijian.render(gWindow.getWidth()/2-Shijian.getWidth(),gWindow.getHeight()/20);
            countdown.render(gWindow.getWidth()/2,gWindow.getHeight()/20);
            countdown.go();
            Start.work=0;
            Start.mCurrentSprite=BUTTON_SPRITE_MOUSE_OUT;
            Rule.work=0;
            Rule.mCurrentSprite=BUTTON_SPRITE_MOUSE_OUT;
            Back.work=0;
            Back.mCurrentSprite=BUTTON_SPRITE_MOUSE_OUT;
            break;
        case betweenrounds:
            countdown.free();
            gSceneTexture.free();
            teacher.freemedia_Teacher();
            gSceneTexture.loadTexture("./black.png");
            gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2 );
            break;
        case finish:
            countdown.free();
            gSceneTexture.free();
            teacher.freemedia_Teacher();
            gSceneTexture.loadTexture("./black.png");
            Gameover.loadFromRenderedText("Time's Up!!!!",purple, bigFont);
            p1word.loadFromRenderedText("Player 1:",white, gFont);
            p2word.loadFromRenderedText("Player 2:",white, gFont);
            gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2 );
            Gameover.render(gWindow.getWidth()/2-Gameover.getWidth()/2,gWindow.getHeight()/20);
            p1word.render(gWindow.getWidth()/20,gWindow.getHeight()/3);
            p2word.render(gWindow.getWidth()*19/20-p2word.getWidth(),gWindow.getHeight()/3);
            break;
    }
}
void close()
{
    TTF_CloseFont( gFont );
    gFont = NULL;
    gSceneTexture.free();
    StartTexture.free();
    RuleTexture.free();
    SDL_DestroyRenderer( gRenderer );
    gWindow.free();
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
}
int main( int argc, char* args[] )
{
    scenario s=starting;
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            bool quit = false;
            SDL_Event e;
            while(!quit)
            {
                while( SDL_PollEvent( &e ) != 0 )
                {
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    gWindow.handleEvent( e );
                    Start.handleEvent(e);
                    Rule.handleEvent(e);
                    Back.handleEvent(e);
                }
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );
                Start.setPosition(gWindow.getWidth()*2/5, gWindow.getHeight()*3/5);
                Rule.setPosition(gWindow.getWidth()*7/17, gWindow.getHeight()*21/30);
                Back.setPosition(gWindow.getWidth()*4/9, gWindow.getHeight()*8/9);
                putMedia(s);
                SDL_RenderPresent( gRenderer );
                if(Rule.mCurrentSprite==BUTTON_SPRITE_MOUSE_UP)
                {
                    s=ruleintro;
                }
                if(Rule.mCurrentSprite==BUTTON_SPRITE_MOUSE_OVER_MOTION)
                {
                	ruleon=true;
				}
				else
				{
					ruleon=false;
				}
				if(Start.mCurrentSprite==BUTTON_SPRITE_MOUSE_OVER_MOTION)
				{
					starton=true;
				}
				else
				{
					starton=false;
				}
                if(Back.mCurrentSprite==BUTTON_SPRITE_MOUSE_OVER_MOTION)
                {
                    backon=true;
                }
                else
                {
                	backon=false;
				}
                if(Back.mCurrentSprite==BUTTON_SPRITE_MOUSE_UP)
                {
                	s=starting;
				}
                if(Start.mCurrentSprite==BUTTON_SPRITE_MOUSE_UP)
                {
                    s=playing;
                }
                if(countdown.end())
                {
                	s=finish;
				}
            }
        }
    }
    close();
    return 0;
}
