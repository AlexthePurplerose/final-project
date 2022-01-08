#include <stdio.h>
#include <string>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "LTexture.h"
#include "LWindow.h"
#include "LButton.h"
#include "Tiempo.h"
#include "Teacher.h"
#include "Student.h"
#include "player1.h"
#include "player2.h"
#include "Score.h"
using namespace std;
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
TTF_Font *mediumFont=NULL;
TTF_Font *smallFont=NULL;
SDL_Color white={255,255,255};
SDL_Color yellow={255,255,0};
SDL_Color purple={221,160,221};
SDL_Color green={189,252,201};
SDL_Color black={255,255,255};
LTexture test;
LTexture gSceneTexture;
LTexture StartTexture;
LTexture RuleTexture;
LTexture BackTexture;
LTexture Shijian;
LTexture Gameover;
LTexture p1word;
LTexture p2word;
LTexture gKeyPressSurfaces[KEY_PRESS_TOTAL];
LTexture Round;
LTexture Win;
Tiempo countdown;
Teacher teacher;
player1 One;
player2 Two;
Score score1;
Score score2;
LButton Start(318,92);
LButton Rule(336,111);
LButton Back(198,113);
int round=1;
ostringstream ROUND;
bool angry;
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
    mediumFont=TTF_OpenFont("./eltipodeletrausado.ttf", 100);
    if( mediumFont == NULL )
    {
        printf( "Failed to load eltipodeletrausado font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    TTF_SetFontStyle(mediumFont, TTF_STYLE_BOLD);
    smallFont=TTF_OpenFont("./eltipodeletrausado.ttf", 28);
    if( smallFont == NULL )
    {
        printf( "Failed to load eltipodeletrausado font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
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
    if(!test.loadFromRenderedText("test",white,mediumFont))
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if(!test.loadFromRenderedText("test",white,smallFont))
    {
        printf( "Failed to render text texture!\n" );
        success = false;
    }
    if(!teacher.loadmedia_Teacher())
    {
        printf("Failed to load Teacher!\n");
        success=false;
    }
    if(!One.loadmedia_movement_player1())
    {
    	printf("Failed to load Player 1!\n");
    	success=false;
	}
	if(!Two.loadmedia_movement_player2())
    {
    	printf("Failed to load Player 2!\n");
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
            One.freemedia_Student();
            Two.freemedia_Student();
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
        	One.freemedia_Student();
        	Two.freemedia_Student();
            gSceneTexture.free();
            StartTexture.free();
            RuleTexture.free();
            Shijian.free();
            countdown.free();
            teacher.freemedia_Teacher();
            One.freemedia_Student();
            Two.freemedia_Student();
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
            Round.loadFromRenderedText(ROUND.str(),white,gFont);
            score1.loadFromRenderedText(score1.sout.str(),white, gFont);
            score2.loadFromRenderedText(score2.sout.str(),white, gFont);
            countdown.loadFromRenderedText(countdown.tout.str(),white,gFont);
            p1word.loadFromRenderedText("Player 1:",black, smallFont);
	        p2word.loadFromRenderedText("Player 2:",black, smallFont);
            gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2 );
            if(!angry) teacher.action(); //teacher
            else teacher.angry();
			score1.play(One);
            score2.play(Two);
            Shijian.render(gWindow.getWidth()*2/5-Shijian.getWidth(),gWindow.getHeight()/20);
            score1.render(0,gWindow.getHeight()/20);
            score2.render(gWindow.getWidth()-score2.getWidth(),gWindow.getHeight()/20);
            Round.render(gWindow.getWidth()*3/5-Round.getWidth()/2,gWindow.getHeight()/20);
            countdown.render(gWindow.getWidth()*2/5,gWindow.getHeight()/20);
            p1word.render(0,0); //待定位 
            p2word.render(0,0); //待定位 
            countdown.go();
            One.handleEvent();
            Two.handleEvent();
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
            One.freemedia_Student();
            Two.freemedia_Student();
            gSceneTexture.loadTexture("./black.png");
            Gameover.loadFromRenderedText("Round Over!!!!",purple, bigFont);
            if(score1.num>score2.num)
            {
	            p1word.loadFromRenderedText("Player 1:",yellow, gFont);
	            p2word.loadFromRenderedText("Player 2:",white, gFont);
	            score1.loadFromRenderedText(score1.sout.str(),yellow, gFont);
	            score2.loadFromRenderedText(score2.sout.str(),white, gFont);
        	}
        	else if(score1.num<score2.num)
        	{
	            p1word.loadFromRenderedText("Player 1:",white, gFont);
	            p2word.loadFromRenderedText("Player 2:",yellow, gFont);
	            score1.loadFromRenderedText(score1.sout.str(),white, gFont);
	            score2.loadFromRenderedText(score2.sout.str(),yellow, gFont);
        	}
        	else
        	{
        		p1word.loadFromRenderedText("Player 1:",white, gFont);
	            p2word.loadFromRenderedText("Player 2:",white, gFont);
	            score1.loadFromRenderedText(score1.sout.str(),white, gFont);
	            score2.loadFromRenderedText(score2.sout.str(),white, gFont);
			}
            gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2 );
            Gameover.render(gWindow.getWidth()/2-Gameover.getWidth()/2,gWindow.getHeight()/20);
            p1word.render(gWindow.getWidth()/20,gWindow.getHeight()/3);
            p2word.render(gWindow.getWidth()*19/20-p2word.getWidth(),gWindow.getHeight()/3);
            score1.render(gWindow.getWidth()/20,gWindow.getHeight()/2);
            score2.render(gWindow.getWidth()*19/20-score2.getWidth(),gWindow.getHeight()/2);
			break;
        case finish:
            countdown.free();
            gSceneTexture.free();
            teacher.freemedia_Teacher();
            One.freemedia_Student();
            Two.freemedia_Student();
            gSceneTexture.loadTexture("./black.png");
            Gameover.loadFromRenderedText("Time's Up!!!!",purple, bigFont);
            if(score1.num>score2.num)
            {
	            p1word.loadFromRenderedText("Player 1:",yellow, gFont);
	            p2word.loadFromRenderedText("Player 2:",white, gFont);
	            score1.loadFromRenderedText(score1.sout.str(),yellow, gFont);
	            score2.loadFromRenderedText(score2.sout.str(),white, gFont);
	            Win.loadFromRenderedText("Player 1 Win!",green,mediumFont);
        	}
        	else if(score1.num<score2.num)
        	{
	            p1word.loadFromRenderedText("Player 1:",white, gFont);
	            p2word.loadFromRenderedText("Player 2:",yellow, gFont);
	            score1.loadFromRenderedText(score1.sout.str(),white, gFont);
	            score2.loadFromRenderedText(score2.sout.str(),yellow, gFont);
	            Win.loadFromRenderedText("Player 2 Win!",green,mediumFont);
        	}
        	else
        	{
        		p1word.loadFromRenderedText("Player 1:",white, gFont);
	            p2word.loadFromRenderedText("Player 2:",white, gFont);
	            score1.loadFromRenderedText(score1.sout.str(),white, gFont);
	            score2.loadFromRenderedText(score2.sout.str(),white, gFont);
	            Win.loadFromRenderedText("TIE!! NO ONE PASS!!",green,mediumFont);
			}
            gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2 );
            Gameover.render(gWindow.getWidth()/2-Gameover.getWidth()/2,gWindow.getHeight()/20);
            p1word.render(gWindow.getWidth()/20,gWindow.getHeight()/3);
            p2word.render(gWindow.getWidth()*19/20-p2word.getWidth(),gWindow.getHeight()/3);
            score1.render(gWindow.getWidth()/20,gWindow.getHeight()/2);
            score2.render(gWindow.getWidth()*19/20-score2.getWidth(),gWindow.getHeight()/2);
            Win.render(gWindow.getWidth()/2-Win.getWidth()/2,gWindow.getHeight()*19/20-2*Win.getHeight());
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
    teacher.freemedia_Teacher();
    One.freemedia_Student();
    Two.freemedia_Student();
    SDL_DestroyRenderer( gRenderer );
    gWindow.free();
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
}
int main( int argc, char* args[] )
{
    scenario s=starting;
    int is1,is2;
    bool roundbegin=true;
    bool roundend=false;
    bool roundgettime=false;
    int roundtick, Currenttick;
    angry=false;
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
                ROUND.str("");
                ROUND.clear();
                ROUND<<"Round "<<round;
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );
                Start.setPosition(gWindow.getWidth()*2/5, gWindow.getHeight()*3/5);
                Rule.setPosition(gWindow.getWidth()*7/17, gWindow.getHeight()*21/30);
                Back.setPosition(gWindow.getWidth()*4/9, gWindow.getHeight()*8/9);
                One.setpos();
                Two.setpos();
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
                if(s==playing&&roundbegin)
                {
                	is1=score1.num;
                	is2=score2.num;
                	roundbegin=false;
				}
                if(!roundgettime&&!teacher.read_newp&&One.ifcheat)
                {
                	score1.caught=true;
                	score2.caught=true;
                	if(Two.ifcheat)
                	{
                		score2.num=is2;
					}
					score1.num=is1;
					roundend=true;
					roundgettime=true;
				}
				else if(!roundgettime&&!teacher.read_newp&&Two.ifcheat)
				{
					score1.caught=true;
                	score2.caught=true;
					score2.num=is2;
					roundend=true;
					roundgettime=true;
				}
				if(!roundgettime&&!teacher.read_newp&&One.ifraise&&!Two.ifraise)
				{
					score1.caught=true;
                	score2.caught=true;
					score1.num=score1.num+score2.num-is2;
					score2.num=is2;
					roundend=true;
					roundgettime=true;
				}
				else if(!roundgettime&&!teacher.read_newp&&!One.ifraise&&Two.ifraise)
				{
					score1.caught=true;
                	score2.caught=true;
					score2.num=score2.num+score1.num-is1;
					score1.num=is1;
					roundend=true;
					roundgettime=true;
				}
				else if(!roundgettime&&!teacher.read_newp&&Two.ifraise&&One.ifraise)
				{
					score1.caught=true;
                	score2.caught=true;
					score1.num=(score1.num+is1)/2;
					score2.num=(score2.num+is2)/2;
					roundend=true;
					roundgettime=true;
				}
				if(roundgettime)
				{
					roundtick=SDL_GetTicks();
					roundgettime=false;
				}
				if(roundend)
				{
					Currenttick=SDL_GetTicks();
					if(Currenttick-roundtick<=2000)
					{
						angry=true;
					}
					else if(Currenttick-roundtick<=6000)
					{
						angry=false;
						s=betweenrounds;
					}
					else
					{
						round++;
						s=playing;
						roundend=false;
						roundbegin=true;
                		score1.caught=false;
                		score2.caught=false;
					}
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
