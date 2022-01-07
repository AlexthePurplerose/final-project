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
    Student() ;
    int player ;
    bool loadmedia_Student (int player );
    bool loadmedia_movement ( int player ) ;
    virtual void cheat (int player ) = 0 ;
    virtual void movement ( int player , event e ) = 0 ;
    bool ifcheat ;
    bool ifraise ;
};
class player1 : public Student
{
    private:

    protected:

    public:
    loadmedia_Student ( int player ) ;
//    bool ifcheat ;
//    bool ifraise ;
};
class player2 : public Student
{
    private:

    protected:

    public:
    loadmedia_Student ( int player ) ;
//    bool ifcheat ;
//    bool ifraise ;
};
#endif