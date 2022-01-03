//
//  Teacher.hpp
//  Final Project
//
//  Created by 盧家雯 on 2022/1/1.
//

#ifndef TEACHER_H
#define TEACHER_H

#include <stdio.h>
#include <iostream>

class Teacher
{
    public:
        Teacher(); //Initializes variables
        ~Teacher(); //Deallocates memory
    
        //void shakenewspaper();
        bool loadmedia_Teacher();
        void freemedia_Teacher();
        void action(); //load media and control teacher's action
        //bool reading_newspaper(); //Teacher reads newspaper or not
        void angry();
        bool read_newp;
    
    private:
        int pos_teach_x, pos_teach_y, pos_newp_x, pos_newp_y;
        
};

#endif
