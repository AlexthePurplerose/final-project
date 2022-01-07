#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "SDL2/SDL.h"

#include <stdio.h>
class Student
{
    private :


    protected:
//    SDL event e ;

    public:
    //int player ;
    bool loadmedia_movement_player1 () ;
    bool loadmedia_movement_player2 () ;
    bool ifcheat ;
    bool ifraise ;
    void freemedia＿Student () ;
};
class player1 : public Student
{
    private:

    int pos_stu_x = 0 ;
    int pos_stu_y = 0 ;
    int pos_note_x = 0 ;
    int pos_note_y = 0 ;

    protected:

    public:
    player1();
    void handleEvent( SDL_Event& e ) ;
//    bool ifcheat ;
//    bool ifraise ;
};
class player2 : public Student
{
    private:

    int pos_stu_x = 0 ;
    int pos_stu_y = 0 ;
    int pos_note_x = 0 ;
    int pos_note_y = 0 ;

    protected:

    public:

    player2();
    void handleEvent( SDL_Event& e ) ;
//    bool ifcheat ;
//    bool ifraise ;

};
#endif