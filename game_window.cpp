//
//  Game_window.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "Game_window.h"
Game_window::Game_window(Point xy,int w,int h,const string& s,int x,string a)
:Window(xy,w,h,s),
title(Point(310,50),"FlipFlaps"),        //create objects
score(Point(310,125),"Score"),
flip_button(Point(650,400),90,45,"Flip!",
            [](Address,Address pw){reference_to<Game_window>(pw).Flip();})
{   //attach objects
    
    flip_count = 0;
    set_difficulty(x);
    set_initials(s);
    //title Text object
    title.set_font_size(50);
    title.set_color(Color::red);
    attach(title);
    
    //score Text object
    score.set_font_size(75);
    attach(score);
    
    //Text object that displays current score
    int temp_score_num = 100*difficulty;
    //convert int to string for use in object
    string temp_score = std::to_string(temp_score_num);
    //pointer to new text object
    score_out = new Text(Point(320,210),temp_score.c_str());
    score_out->set_font_size(100);
    score_out->set_color(Color::red);
    attach(*score_out);
    
    //Text object to display current level
    string temp_level ="Level: "+ std::to_string(difficulty);
    level = new Text(Point(550,75),temp_level.c_str());
    level->set_font_size(50);
    level->set_color(Color::red);
    attach(*level);
    
    //button object that flips pancakes
    attach(flip_button);
    
    //plate line object
    plate.add(Point(275,600),Point(525,600));
    plate.set_style(Line_style(Line_style::solid, 5));
    attach(plate);
    
    spatula_height = 570;
    create_spatula();
    
    //creates pancakes
    create_pancake(difficulty);
    
    //Text object used to display minimum number of flips to win
    string temp_solution = "Can be done in "+ std::to_string(solution_num)+" flips";
    done_in_x_flips = new Text(Point(550,100),temp_solution.c_str());
    done_in_x_flips->set_font_size(20);
    done_in_x_flips->set_color(Color::blue);
    attach(*done_in_x_flips);
    
}
void Game_window::set_difficulty(int x){
    difficulty=x;
}

void Game_window::set_initials(string s){
    initials = s;
}

void Game_window::create_pancake(int x){
    int height = 570;
    perm = perm_pancake(x);
    solution();
    for (int i=0; i<x; ++i) {
        pancakes.push_back(new Pancake(Point(300-(15*perm[i]),height-(20*i)),200+(30*perm[i]),20));
        height = height-10;
    }
    disp_pancake();
}

vector<int> Game_window::perm_pancake(int x){
    for (int i =1; i<=x; ++i) {
        dummy.push_back(i);
        sorted.push_back(i);
    }
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(dummy.begin(),dummy.end(),default_random_engine(seed));
    reverse(sorted.begin(),sorted.end());
    
    return dummy;
}

void Game_window::disp_pancake(){
    for (int j=0; j<pancakes.size(); ++j) {
       // pancakes[j]->set_fill_color(Color::brown);
        attach(*pancakes[j]);
    }
}
int Game_window::handle(int e) {
    switch(e)
    {
        case FL_FOCUS:
        case FL_UNFOCUS:
            return 1;
        case FL_KEYBOARD:
            int key = Fl::event_key();
            if (spatula_level==0 && spatula_level!=pancakes.size()-2) {
                switch(key)
                {
                    case FL_Up:
                        spatula_level=spatula_level + 1;
                        detach(*spatula);
                        move_spatula(-30);
                        redraw();
                        return 1;
                }
            }
            if (spatula_level<pancakes.size()-2 && spatula_level>0) {
                switch(key)
                {
                    case FL_Up:
                        spatula_level=spatula_level + 1;
                        detach(*spatula);
                        move_spatula(-30);
                        redraw();
                        return 1;
                    case FL_Down:
                        spatula_level=spatula_level - 1;
                        detach(*spatula);
                        move_spatula(30);
                        redraw();
                        return 1;
                }
            }
            if (spatula_level == pancakes.size()-2 && spatula_level!=0) {
                switch(key)
                {
                    case FL_Down:
                        spatula_level=spatula_level - 1;
                        detach(*spatula);
                        move_spatula(30);
                        redraw();
                        return 1;
                }
            }
    }
    return Fl_Window::handle(e);
}

void Game_window::move_spatula(int movement){
    spatula_height = spatula_height + movement;
    create_spatula();
}

void Game_window::create_spatula(){
    spatula = new Open_polyline;
    spatula->add(Point(0,spatula_height));
    spatula->add(Point(140,spatula_height));
    spatula->add(Point(165,spatula_height+24));
    spatula->add(Point(600,spatula_height+24));
    spatula->set_color(Color::black);
    spatula->set_style(Line_style(Line_style::solid, 5));
    attach(*spatula);
}

void Game_window::flip(int pos){
    flip_count = flip_count +1;
    solution_score();
    for (int j=0; j<pancakes.size(); ++j) {
        detach(*pancakes[j]);
    }
    pancakes.clear();
    reverse(perm.begin()+pos,perm.end());
    int height = 570;
    for (int i=0; i<difficulty; ++i) {
        pancakes.push_back(new Pancake(Point(300-(15*perm[i]),height-(20*i)),200+(30*perm[i]),20));
        height = height-10;
    }
    disp_pancake();
}

void Game_window::solution(){
    reverse(perm.begin(),perm.end());
    solution_vec = find_solution(perm);
    solution_num = solution_vec->size();
    if (solution_num == 0) {
        perm_pancake(difficulty);
        solution();
    }
    reverse(perm.begin(),perm.end());
}

void Game_window::solution_score(){
    if (flip_count <= solution_num) {
        scoring = 100 * difficulty;
    }
    else{
        scoring = (100-10*(flip_count-solution_num))*difficulty;
    }
    detach(*score_out);
    string temp = std::to_string(scoring);
    score_out = new Text(Point(320,210),temp.c_str());
    score_out->set_font_size(100);
    score_out->set_color(Color::red);
    attach(*score_out);
    
}

void Game_window::Flip(){
    flip(spatula_level);
    //Text object used to display flip number
    detach(*flip_out);
    string temp_flip_count = "Current flip # "+std::to_string(flip_count);
    flip_out = new Text(Point(550,125),temp_flip_count.c_str());
    flip_out->set_font_size(20);
    flip_out->set_color(Color::blue);
    attach(*flip_out);
    redraw();
    //check to see if score is below zero
    if (scoring <= 0) {
        //if zero then game is over
        hide();
        Score_window score_win(Point(100,0),800,700,"FlipFlap",scoring,initials);
        gui_main();
    }
    game_won = 0;
    //check for game completion
    for (int i = 0; i<difficulty; ++i) {
        if (sorted[i]==perm[i]) {
            game_won = game_won+1;
        }
    }
    if (game_won == difficulty) {
        hide();
        Score_window score_win(Point(100,0),800,700,"FlipFlap",scoring,initials);
        gui_main();
    }
    
}