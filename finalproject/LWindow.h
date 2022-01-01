#ifndef LWINDOW_H
#define LWINDOW_H
extern SDL_Renderer* gRenderer;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
class LWindow
{
	public:
		//Intializes internals
		LWindow();

		//Creates window
		bool init();

		//Creates renderer from internal window
		SDL_Renderer* createRenderer();

		//Handles window events
		void handleEvent( SDL_Event& e );

		//Deallocates internals
		void free();

		//Window dimensions
		int getWidth();
		int getHeight();

		//Window focii
		bool isMinimized();

	private:
		//Window data
		SDL_Window* mWindow;

		//Window dimensions
		int mWidth;
		int mHeight;

		//Window focus
		bool mFullScreen;
		bool mMinimized;
};
extern LWindow gWindow;
#endif
