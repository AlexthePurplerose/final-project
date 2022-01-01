#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "LTexture.h"
#include "LWindow.h"
#include "LButton.h"
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
LTexture test;
LTexture gSceneTexture;
LTexture StartTexture;
LTexture RuleTexture;
LTexture BackTexture;
LButton Start(318,92);
LButton Rule(336,111);
LButton Back(198,113);
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
			}
		}
	}
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
			gSceneTexture.loadTexture("./gamestart.png");
			StartTexture.loadFromFile("./gamestartbutton.png");
			RuleTexture.loadFromFile("./rulebutton.png");
			gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2);
			StartTexture.render(gWindow.getWidth()*2/5, gWindow.getHeight()*3/5,NULL,-10,NULL,SDL_FLIP_NONE );
			RuleTexture.render( gWindow.getWidth()*7/17, gWindow.getHeight()*11/15,NULL,-10,NULL,SDL_FLIP_NONE );
			Start.work=1;
			Rule.work=1;
			Back.work=0;
			Back.mCurrentSprite=BUTTON_SPRITE_MOUSE_OUT;
			break;
		case ruleintro:
			gSceneTexture.free();
			StartTexture.free();
			RuleTexture.free();
			gSceneTexture.loadTexture("./rule.png");
			BackTexture.loadFromFile("./backbutton.png");
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
			gSceneTexture.render( ( gWindow.getWidth() - gSceneTexture.getWidth() ) / 2, ( gWindow.getHeight() - gSceneTexture.getHeight() ) / 2 );
			Start.work=0;
			Start.mCurrentSprite=BUTTON_SPRITE_MOUSE_OUT;
			Rule.work=0;
			Rule.mCurrentSprite=BUTTON_SPRITE_MOUSE_OUT;
			Back.work=0;
			Back.mCurrentSprite=BUTTON_SPRITE_MOUSE_OUT;
	}
}
void close()
{
	gSceneTexture.free();
	StartTexture.free();
	RuleTexture.free();
	SDL_DestroyRenderer( gRenderer );
	gWindow.free();
	IMG_Quit();
	SDL_Quit();
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
				Rule.setPosition(gWindow.getWidth()*7/17, gWindow.getHeight()*11/15);
				Back.setPosition(gWindow.getWidth()*4/9, gWindow.getHeight()*8/9);
				putMedia(s);
				SDL_RenderPresent( gRenderer );
				if(Rule.mCurrentSprite==BUTTON_SPRITE_MOUSE_UP)
				{
					s=ruleintro;
				}
				if(Back.mCurrentSprite==BUTTON_SPRITE_MOUSE_UP)
				{
					s=starting;
				}
				if(Start.mCurrentSprite==BUTTON_SPRITE_MOUSE_UP)
				{
					s=playing;
				}
			}
		}
	}
	close();
	return 0;
}
