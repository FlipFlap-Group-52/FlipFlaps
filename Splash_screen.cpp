//
//  Splash_screen.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "Splash_screen.h"
Splash_screen::Splash_screen(Point xy,int w,int h,const string& s)
:Window(xy,w,h,s),
play_button(Point(300,300),90,30,"Play",cb_play),
score_button(Point(300,360),90,30,"High Scores",cb_score),
instructions_button(Point(300,420),90,30,"Instructions",cb_instructions),
title(Point(300,50),"FlipFlaps")
{
    attach(play_button);
    attach(score_button);
    attach(instructions_button);
    attach(title);
}

void Splash_screen::cb_play(Address,Address pw){
    reference_to<Splash_screen>(pw).play();
}
void Splash_screen::play(){
    
}
void Splash_screen::cb_score(Address,Address pw){
    reference_to<Splash_screen>(pw).score();
}
void Splash_screen::score(){
    
}
void Splash_screen::cb_instructions(Address,Address pw){
    reference_to<Splash_screen>(pw).instructions();
}
void Splash_screen::instructions(){
    
}
