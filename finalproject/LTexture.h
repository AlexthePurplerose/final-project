#ifndef LTEXTURE_H
#define LTEXTURE_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
extern TTF_Font *gFont;
class LTexture
{
	public:
		LTexture();
		~LTexture();

		bool loadFromFile( std::string path );
		bool loadTexture( std::string path );
		#if defined(SDL_TTF_MAJOR_VERSION)
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif

		void free();

		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		void setBlendMode( SDL_BlendMode blending );

		void setAlpha( Uint8 alpha );
		
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		int getWidth();
		int getHeight();

		int mWidth;
		int mHeight;
	private:
		SDL_Texture* mTexture;
};
#endif
