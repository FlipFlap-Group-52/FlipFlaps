//
//  setup_window.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "setup_window.h"
Setup_window::Setup_window(Point xy,int w,int h,const string& s)
:Window(xy,w,h,s),
diff(Point(375,125),70,20,Menu::vertical,"Difficulty"),
initials(Point(375,100),70,20,"Initals"),
title(Point(300,50),"FlipFlaps")
{
    diff.attach(new Button(Point(0,0),0,0,"2",
                           [](Address,Address pw){reference_to<Setup_window>(pw).diff2();}));
    diff.attach(new Button(Point(0,0),0,0,"3",
                           [](Address,Address pw){reference_to<Setup_window>(pw).diff3();}));
    diff.attach(new Button(Point(0,0),0,0,"4",
                           [](Address,Address pw){reference_to<Setup_window>(pw).diff4();}));
    diff.attach(new Button(Point(0,0),0,0,"5",
                           [](Address,Address pw){reference_to<Setup_window>(pw).diff5();}));
    diff.attach(new Button(Point(0,0),0,0,"6",
                           [](Address,Address pw){reference_to<Setup_window>(pw).diff6();}));
    diff.attach(new Button(Point(0,0),0,0,"7",
                           [](Address,Address pw){reference_to<Setup_window>(pw).diff7();}));
    diff.attach(new Button(Point(0,0),0,0,"8",
                           [](Address,Address pw){reference_to<Setup_window>(pw).diff8();}));
    diff.attach(new Button(Point(0,0),0,0,"9",
                           [](Address,Address pw){reference_to<Setup_window>(pw).diff9();}));
    attach(diff);
    attach(initials);
    title.set_font_size(50);
    title.set_color(Color::red);
    attach(title);
}
void Setup_window::diff2(){
    difficulty = 2;
    hide();
    Pancake(Point(275,570),250,20,difficulty);
}
void Setup_window::diff3(){
    difficulty = 3;
    hide();
    Pancake(Point(275,570),250,20,difficulty);
}
void Setup_window::diff4(){
    difficulty = 4;
    hide();
    Pancake(Point(275,570),250,20,difficulty);
}
void Setup_window::diff5(){
    difficulty = 5;
    hide();
    Pancake(Point(275,570),250,20,difficulty);
}
void Setup_window::diff6(){
    difficulty = 6;
    hide();
    Pancake(Point(275,570),250,20,difficulty);
}
void Setup_window::diff7(){
    difficulty = 7;
    hide();
    Pancake(Point(275,570),250,20,difficulty);
}
void Setup_window::diff8(){
    difficulty = 8;
    hide();
    Pancake(Point(275,570),250,20,difficulty);
}
void Setup_window::diff9(){
    difficulty = 9;
    hide();
    Pancake(Point(275,570),250,20,difficulty);
}
