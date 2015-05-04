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
            [](Address,Address pw){reference_to<Score_window>(pw).quit();}),
score_button(Point(350,550),100,50,"High Scores",
             [](Address,Address pw){reference_to<Score_window>(pw).score();})
{
    if (x>0) {
        set_initials(a);
        win_lose = new Text(Point(200,150),"You Won!");
        win_lose->set_font_size(100);
        win_lose->set_color(Color::red);
        attach(*win_lose);
        
        score_text = new Text(Point(300,240),"Score:");
        score_text->set_font_size(75);
        score_text->set_color(Color::blue);
        attach(*score_text);
        
        score1 = std::to_string(x);
        final_score = new Text(Point(320,340),score1.c_str());
        final_score->set_font_size(100);
        final_score->set_color(Color::blue);
        attach(*final_score);
        write_score(initials,score1);
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
    attach(score_button);
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
void Score_window::write_score(string initial,string t){
    ofs.open("Score_file.txt", std::ios_base::app);
    if (ofs.is_open()) {
        ofs<< initial << "   " << t << "\n";
        ofs.close();
    }
}void Score_window::set_initials(string s){
    initials = s;
}

void Score_window::score(){
    hide();
	high_score_window win1(Point(100,0),800,675,"High Scores");
	gui_main();
}




