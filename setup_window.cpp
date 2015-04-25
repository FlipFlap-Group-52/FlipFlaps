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
diff(Point(375,175),70,20,Menu::vertical,"Difficulty"),
initials(Point(375,150),70,20,"Initals"),
title(Point(300,50),"FlipFlaps"),
word{Point{190,130},"Choose a Difficulty:"},
contin(Point(450,150),70,20,"Continue",
                [](Address,Address pw){reference_to<Setup_window>(pw).continue_button();}),
start(Point(300,450),150,100,"Start",
      [](Address,Address pw){reference_to<Setup_window>(pw).start_button();})
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
	diff.hide();
    attach(contin);
    attach(initials);
    title.set_font_size(50);
    title.set_color(Color::red);
    attach(title);
	word.set_font_size(50);
	word.set_color(Color::blue);
	attach(word);
    attach(start);
    start.hide();
	
}
//added the continue button
void Setup_window::continue_button(){
    if (initials.get_string() == ""){
        enter_initials = new Text(Point(200,150),"Please enter initials");
        enter_initials->set_font_size(50);
        enter_initials->set_color(Color::red);
        attach(*enter_initials);
    }
    else{
        diff.show();
    }
}
void Setup_window::diff2(){
    difficulty = 2;
	start.show();
}
void Setup_window::diff3(){
    difficulty = 3;
    start.show();
}
void Setup_window::diff4(){
    difficulty = 4;
    start.show();
}
void Setup_window::diff5(){
    difficulty = 5;
    start.show();
}
void Setup_window::diff6(){
    difficulty = 6;
    start.show();
}
void Setup_window::diff7(){
    difficulty = 7;
    start.show();
}
void Setup_window::diff8(){
    difficulty = 8;
    start.show();
}
void Setup_window::diff9(){
    difficulty = 9;
    start.show();
}
void Setup_window::start_button(){
    hide();
    Game_window game_win(Point(100,0),800,700,"FlipFlap",difficulty);
    cout<<"diff: "<<difficulty;
    gui_main();
}
