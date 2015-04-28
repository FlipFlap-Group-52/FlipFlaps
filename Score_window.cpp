//
//  Score_window.cpp
//  
//
//  Created by Jordan Blissett on 4/20/15.
//
//

#include "Score_window.h"
Score_window::Score_window(Point xy,int w,int h,const string& s,int x,string a)
:Window(xy,w,h,s),
title(Point(310,50),"FlipFlaps"),
replay_button(Point(150,550),100,50,"Replay",
              [](Address,Address pw){reference_to<Score_window>(pw).replay();}),
quit_button(Point(550,550),100,50,"Quit",
            [](Address,Address pw){reference_to<Score_window>(pw).quit();})
{
    if (x>0) {
        win_lose = new Text(Point(200,150),"You Won!");
        win_lose->set_font_size(100);
        win_lose->set_color(Color::red);
        attach(*win_lose);
        
        score_text = new Text(Point(300,240),"Score:");
        score_text->set_font_size(75);
        score_text->set_color(Color::blue);
        attach(*score_text);
        
        score = std::to_string(x);
        final_score = new Text(Point(320,340),score.c_str());
        final_score->set_font_size(100);
        final_score->set_color(Color::blue);
        attach(*final_score);
        
        high_score_window::write_score(a, score);
    }
    else{
        win_lose = new Text(Point(175,150),"Game over! Number of flips exceeded.");
        win_lose->set_font_size(25);
        win_lose->set_color(Color::red);
        attach(*win_lose);
    }
    title.set_font_size(50);
    title.set_color(Color::red);
    attach(title);
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



