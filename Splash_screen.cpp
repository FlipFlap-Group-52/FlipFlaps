//
//  Splash_screen.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "Splash_screen.h"
#include "setup_window.h"
Splash_screen::Splash_screen(Point xy,int w,int h,const string& s)
:Window(xy,w,h,s),
background(Point(0,0),"pancake1.jpg"),
play_button(Point(380,350),90,30,"Play",
            [](Address,Address pw){reference_to<Splash_screen>(pw).play();}),
score_button(Point(380,410),90,30,"High Scores",
             [](Address,Address pw){reference_to<Splash_screen>(pw).score();}),
instructions_button(Point(380,470),90,30,"Instructions",
                    [](Address,Address pw){reference_to<Splash_screen>(pw).instructions_cb();}),
title(Point(330,80),"FlipFlaps"),
team(Point(400,150),"Team 52"),
name1(Point(380,200),"Jordan Blissett"),
name2(Point(380,250),"Dakota Cuttrell"),
name3(Point(375,300),"Benjamin Anderson"),
play_button_rectangle(Point(380,350),90,30),
score_button_rectangle(Point(380,410),90,30),
instructions_button_rectangle(Point(380,470),90,30),
play_text(Point(410,370),"Play"),
score_text(Point(400,430),"Score"),
instructions_text(Point(390,490),"Instructions")
{
    title.set_font_size(50);
    title.set_color(Color::red);
	attach(background);
	attach(play_text);
	attach(score_text);
	attach(instructions_text);
	attach(title);
	attach(team);
	attach(name1);
	attach(name2);
	attach(name3);
    attach(play_button);
    attach(score_button);
    attach(instructions_button);
	attach(play_button_rectangle);
    attach(score_button_rectangle);
    attach(instructions_button_rectangle);

}


void Splash_screen::play(){
    hide();
    Setup_window win(Point(100,0),800,675,"Difficulty");
    gui_main();
}
void Splash_screen::score(){
    hide();
	high_score_window win1(Point(100,0),800,675,"High Scores");
	gui_main();
}
void Splash_screen::instructions_cb(){
    hide();
	instructions Instruct_win(Point(100,0),800,675,"Instructions");
    gui_main();
}
