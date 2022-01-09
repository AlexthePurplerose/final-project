//changed
#ifndef SCORE_H
#define SCORE_H
#include "LTexture.h"
#include <string>
#include <sstream>
#include "player1.h"
#include "player2.h"
using namespace std;
class Score:public LTexture{
	public:
		ostringstream sout;
		void reset();
		int num;
		void play(player1 One);
		void play(player2 Two);
		bool caught;
	private:
		int downtick;
		int mnum;
		bool count;
};
#endif
