//
//  setup_window.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "setup_window.h"
//initializing the window, texts and buttons

Setup_window::Setup_window(Point xy,int w,int h,const string& s)
:Window(xy,w,h,s),
diff(Point(500,250),125,40,Menu::vertical,"Difficulty"),
initials(Point(350,175),100,30,"Initials"),
title(Point(300,50),"FlipFlaps"),
word{Point{190,130},"Choose a Difficulty:"},
contin(Point(450,175),100,30,"Continue",
                [](Address,Address pw){reference_to<Setup_window>(pw).continue_button();}),
start(Point(150,325),250,125,"Start",
      [](Address,Address pw){reference_to<Setup_window>(pw).start_button();})
{
//adding the button for difficulty

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
//attachments
    attach(diff);
    diff.hide();
    attach(contin);
    attach(initials);
    /*enter_initials = new Text(Point(0,200),"Please enter initials");
    enter_initials->set_font_size(50);
    enter_initials->set_color(Color::red);
    attach(*enter_initials);
    enter_initials->hide();*/
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
       // enter_initials->show();
    }
    else{
        player = initials.get_string();
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
    Game_window game_win(Point(100,0),800,700,"FlipFlap",difficulty,player);
    gui_main();
}
