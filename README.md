Alex:1/8 00:22 main, LTexture.h, Student.h, Student.cpp is changed. Files player1.h, player1.cpp, player2.h, player2.cpp is added. 

Alex:1/9 14:43 main, player1.h, player1.cpp, player2.h, player2.cpp is updated. Players can control the students simultaneously now.

chiawen: 1/9 5:00 Student.cpp, player1.cpp, player1.h, player2.h, player2.cpp, Teacher.h, Teacher.cpp and some images are updated. 
PS: You can add following codes in putmedia function of main.cpp to call teacher.angry():
/*
if ( !teacher.ifread) {
  if (One.ifcheat || Two.ifcheat) teacher.angry();
  else if (One.ifcheat && Two.ifraise) teacher.angry();
  else if (One.ifraise && Two.ifcheat) teacher.angry();
  else if (One.ifraise && Two.ifraise) teacher.angry();
  else teacher.ifangry = false;
}
else teacher.ifangry = false;
  */

            
          
