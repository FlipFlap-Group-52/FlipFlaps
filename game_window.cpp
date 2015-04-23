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
//ground(Point(0,350),800,325),
title(Point(310,50),"FlipFlaps"),
score(Point(310,125),"Score"),
//level_out(Point(550,75),70,35,"Level"),
flip_button(Point(650,400),90,45,"Flip!",
            [](Address,Address pw){reference_to<Game_window>(pw).Flip();})
{
    flip_count = 0;
    set_difficulty(x);
    //ground.set_fill_color(Color::green);
    //attach(ground);
    title.set_font_size(50);
    title.set_color(Color::red);
    attach(title);
    score.set_font_size(75);
    attach(score);
    int temp_score_num = 100*difficulty;
    string temp_score = std::to_string(temp_score_num);
    score_out = new Text(Point(320,210),temp_score.c_str());
    score_out->set_font_size(100);
    score_out->set_color(Color::red);
    attach(*score_out);
    string temp_level ="Level: "+ std::to_string(difficulty);
    level = new Text(Point(550,75),temp_level.c_str());
    level->set_font_size(50);
    level->set_color(Color::red);
    attach(*level);

    //level_out.put(ss.str());
    attach(flip_button);
    plate.add(Point(275,600),Point(525,600));
    plate.set_style(Line_style(Line_style::solid, 5));
    attach(plate);
    spatula_height = 570;
    create_spatula();
    create_pancake(difficulty);
    string temp_solution = "Can be done in "+ std::to_string(solution_num)+" flips";
    done_in_x_flips = new Text(Point(550,100),temp_solution.c_str());
    done_in_x_flips->set_font_size(20);
    done_in_x_flips->set_color(Color::blue);
    attach(*done_in_x_flips);
    
}

void Game_window::Flip(){
    flip(spatula_level);
    detach(*flip_out);
    string temp_flip_count = "Current flip # "+std::to_string(flip_count);
    flip_out = new Text(Point(550,125),temp_flip_count.c_str());
    flip_out->set_font_size(20);
    flip_out->set_color(Color::blue);
    attach(*flip_out);
    redraw();
    if (scoring <= 0) {
        hide();
        Score_window score_win(Point(100,0),800,700,"FlipFlap",scoring);
        gui_main();
        
    }
    
    game_won = 0;
    for (int i = 0; i<difficulty; ++i) {
        if (sorted[i]==perm[i]) {
            game_won = game_won+1;
        }
    }
    if (game_won == difficulty) {
        hide();
        Score_window score_win(Point(100,0),800,700,"FlipFlap",scoring);
        gui_main();
    }
    
}