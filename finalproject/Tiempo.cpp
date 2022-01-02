#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include "LTexture.h"
#include "LWindow.h"
#include "Tiempo.h"
using namespace std;
void Tiempo::go()
{
	int min,sec;
	second--;
	tout.str("");
	tout.clear();
	min=second/60;
	sec=second%60;
	if(sec>=10)
	{
		tout<<min<<":"<<sec;
	}
	else
	{
		tout<<min<<":0"<<sec;
	}
}

void Tiempo::reset()
{
	second=120;
	tout<<"2:00";
}
bool Tiempo::end()
{
	return !second;
}
