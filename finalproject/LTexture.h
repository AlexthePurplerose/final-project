#ifndef LTEXTURE_H
#define LTEXTURE_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <sstream>
enum KeyPressSurfaces
{
    KEY_PRESS_SURFACE_DEFAULT1=0,
    KEY_PRESS_SURFACE_DEFAULT2=1,
    KEY_PRESS_SURFACE_A=2,
    KEY_PRESS_SURFACE_D=3,
    KEY_PRESS_SURFACE_LEFT=4,
    KEY_PRESS_SURFACE_RIGHT=5,
    KEY_PRESS_TOTAL=6
};
extern int rd;
class LTexture
{
	public:
		LTexture();
		~LTexture();

		bool loadFromFile( std::string path );
		bool loadTexture( std::string path );
		#if defined(SDL_TTF_MAJOR_VERSION)
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor,TTF_Font *gFont );
		#endif

		void free();

		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		void setBlendMode( SDL_BlendMode blending );

		void setAlpha( Uint8 alpha );
		
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
		bool loadTexture2( std::string path ,int height, int width);
		int getWidth();
		int getHeight();

		int mWidth;
		int mHeight;
	private:
		SDL_Texture* mTexture;
};
extern LTexture gKeyPressSurfaces[KEY_PRESS_TOTAL];
#endif
