//
//  Splash_screen.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "Splash_screen.h"
Splash_screen::Splash_screen(Point xy,int w,int h,const string& s)
:Simple_window(xy,w,h,s),
play_button(Point(300,300),70,20,"Play",cb_play),
score_button(Point(300,340),70,20,"High Scores",cb_score),
instructions_button(Point(300,380),70,20,"Instructions",cb_instructions)
{
    attach(play_button);
    attach(score_button);
    attach(instructions_button);
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
