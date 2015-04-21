//
//  Score_window.cpp
//  
//
//  Created by Jordan Blissett on 4/20/15.
//
//

#include "Score_window.h"
Score_window::Score_window(Point xy,int w,int h,const string& s,string r)
:Window(xy,w,h,s),
title(Point(310,50),"FlipFlaps"),
score(Point(310,150),"Score"),
final_score(Point(350,150),r),
replay_button(Point(550,400),70,35,"Replay",
              [](Address,Address pw){reference_to<Score_window>(pw).replay();}),
quit_button(Point(400,400),70,35,"Quit",
            [](Address,Address pw){reference_to<Score_window>(pw).quit();})
{
    title.set_font_size(50);
    title.set_color(Color::red);
    attach(title);
    attach(score);
    final_score.set_font_size(100);
    final_score.set_color(Color::red);
    attach(final_score);
    attach(replay_button);
    attach(quit_button);
}
void Score_window::replay(){
    hide();
    Setup_window win(Point(100,0),800,700,"Difficulty");
    gui_main();
}
void Score_window::quit(){
    hide();
    
}