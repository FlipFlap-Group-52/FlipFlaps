//
//  Game_window.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "Game_window.h"
Game_window::Game_window(Point xy,int w,int h,const string& s,int x)
:Window(xy,w,h,s),
ground(Point(0,350),800,325),
title(Point(310,50),"FlipFlaps"),
//level(Point(550,75),"Level"),
//diff(Point(600,75),)
flip_button(Point(550,400),35,20,"Flip!",
            [](Address,Address pw){reference_to<Game_window>(pw).Flip();})
{
    set_difficulty(x);
    ground.set_fill_color(Color::green);
    //attach(ground);
    title.set_font_size(50);
    title.set_color(Color::red);
    attach(title);
    //level_out.set_font_size(50);
    //level_out.set_color(Color::red);
    //ostringstream ss;
    //ss<<' '<<x;
    //diff = std::to_string(difficulty);
    //level_out.put(diff);
    //attach(level_out);
    attach(flip_button);
    plate.add(Point(275,600),Point(525,600));
    plate.set_style(Line_style(Line_style::solid, 5));
    attach(plate);
    spatula_height = 570;
    create_spatula();
    create_pancake(difficulty);
   
}

void Game_window::Flip(){
    flip(spatula_level);
    redraw();
    game_won = 0;
    for (int i = 0; i<difficulty; ++i) {
        if (sorted[i]==perm[i]) {
            game_won = game_won+1;
        }
    }
    if (game_won == difficulty) {
        string final_score = std::to_string(scoring);
        hide();
        Score_window score_win(Point(100,0),800,700,"FlipFlap",final_score);
        gui_main();
    }
    
}