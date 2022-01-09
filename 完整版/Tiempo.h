#ifndef TIEMPO
#define TIEMPO
#include "LTexture.h"
#include <string>
#include <sstream>
using namespace std;
class Tiempo: public LTexture{
	public:
		bool end();
		ostringstream tout;
		void go();
		void reset();
	private:
		int second;
};
#endif
