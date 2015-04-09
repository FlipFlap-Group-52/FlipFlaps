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
play_button(Point(300,300),90,30,"Play",
            [](Address,Address pw){reference_to<Splash_screen>(pw).play();}),
score_button(Point(300,360),90,30,"High Scores",
             [](Address,Address pw){reference_to<Splash_screen>(pw).score();}),
instructions_button(Point(300,420),90,30,"Instructions",
                    [](Address,Address pw){reference_to<Splash_screen>(pw).instructions();}),
title(Point(330,80),"FlipFlaps")
team(Point(400,150),"Team 52");
name1(Point(380,200),"Jordan Blissett");
name2(Point(380,250),"Dakota Cuttrell");
name3(Point(375,300),"Benjamin Anderson");
background(Point(0,0),"pancake1.jpg");

{
    attach(play_button);
    attach(score_button);
    attach(instructions_button);
    title.set_font_size(50);
    title.set_color(Color::red);
    attach(title);
	attach(background);
	attach(title);
	attach(team);
	attach(name1);
	attach(name2);
	attach(name3);

}


void Splash_screen::play(){
    hide();
    Setup_window win(Point(100,0),800,675,"Difficulty");
    gui_main();
}
void Splash_screen::score(){
    
}
void Splash_screen::instructions(){
    
}
