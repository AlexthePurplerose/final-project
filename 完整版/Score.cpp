//changed
#include "LTexture.h"
#include "player1.h"
#include "player2.h"
#include <string>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "Score.h"
void Score::reset()
{
	num=0;
	downtick=0;
	mnum=0;
	count=false;
	caught=false;
}
void Score::play(player1 One)
{
	int Currenttick;
	if(One.ifcheat&&!count)
	{
		count=true;
		downtick=SDL_GetTicks();
		mnum=num;
	}
	if(count&&!caught)
	{
		Currenttick=SDL_GetTicks();
		if(Currenttick-downtick<=2999)
		{
			num=mnum+(Currenttick-downtick);
		}
		else if(Currenttick-downtick<=6999)
		{
			num=mnum+2*(Currenttick-downtick);
		}
		else
		{
			num=mnum+3*(Currenttick-downtick);
		}
	}
	if(count&&caught)
	{
		count=false;
	}
	if(!One.ifcheat&&count)
	{
		count=false;
	}
	sout.str("");
	sout.clear();
	if(num>=100000)
	{
		sout<<"Score: "<<num;
	}
	else if(num>=10000)
	{
		sout<<"Score: 0"<<num;
	}
	else if(num>=1000)
	{
		sout<<"Score: 00"<<num;
	}
	else if(num>=100)
	{
		sout<<"Score: 000"<<num;
	}
	else if(num>=10)
	{
		sout<<"Score: 0000"<<num;
	}
	else
	{
		sout<<"Score: 00000"<<num;
	}
}

void Score::play(player2 Two)
{
	int Currenttick;
	if(Two.ifcheat&&!count)
	{
		count=true;
		downtick=SDL_GetTicks();
		mnum=num;
	}
	if(count&&!caught)
	{
		Currenttick=SDL_GetTicks();
		if(Currenttick-downtick<=2999)
		{
			num=mnum+(Currenttick-downtick);
		}
		else if(Currenttick-downtick<=6999)
		{
			num=mnum+2*(Currenttick-downtick);
		}
		else
		{
			num=mnum+3*(Currenttick-downtick);
		}
	}
	if(count&&caught)
	{
		count=false;
	}
	if(!Two.ifcheat&&count)
	{
		count=false;
	}
	sout.str("");
	sout.clear();
	if(num>=100000)
	{
		sout<<"Score: "<<num;
	}
	else if(num>=10000)
	{
		sout<<"Score: 0"<<num;
	}
	else if(num>=1000)
	{
		sout<<"Score: 00"<<num;
	}
	else if(num>=100)
	{
		sout<<"Score: 000"<<num;
	}
	else if(num>=10)
	{
		sout<<"Score: 0000"<<num;
	}
	else
	{
		sout<<"Score: 00000"<<num;
	}
}
