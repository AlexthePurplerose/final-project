#ifndef LBUTTON_H
#define LBUTTON_H
#include"LTexture.h"
enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
};
class LButton
{
	public:
		//Initializes internal variables
		LButton(int w, int h);

		//Sets top left position
		void setPosition( int x, int y );

		//Handles mouse event
		void handleEvent( SDL_Event& e );
		
		LButtonSprite mCurrentSprite;
	
		bool work;
	private:
		//Top left position
		SDL_Point mPosition;
		
		int BUTTON_WIDTH;
		
		int BUTTON_HEIGHT;
};
#endif
