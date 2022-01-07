#ifndef PLAYERONE
#define PLAYERONE
#include "Student.h"
#include <SDL.h>
class player1 : public Student
{
    private:

    int pos_stu_x ;
    int pos_stu_y ;
    int pos_note_x ;
    int pos_note_y ;

    protected:

    public:
    player1();
    void handleEvent( SDL_Event& e ) ;
//    bool ifcheat ;
//    bool ifraise ;
};
#endif
