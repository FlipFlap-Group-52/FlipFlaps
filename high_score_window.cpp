//
//  high_score_window.cpp
//  
//
//  Created by Dakota Cuttrell on 4/23/15.
//
//

#include "high_score_window.h"

high_score_window::high_score_window(Point xy,int w,int h,const string& s)
:Window(xy,w,h,s),
title(Point(310,50),"FlipFlaps"),
the_winners(Point(250,150),"Top 5 Scores!"),
back_Button(Point(100,50),70,35,"Back",
            [](Address,Address pw){reference_to<high_score_window>(pw).back();})
{

    title.set_font_size(50);
    the_winners.set_font_size(50);
    title.set_color(Color::red);
    the_winners.set_color(Color::blue);
    attach(title);
    attach(the_winners);
	attach(back_Button);
    read_score();
/*
vector<int>scores;
int high_score;
scores.push_back(high_score);
{
	sort(scores);
}
*/
}

void high_score_window::read_score(){
    ifs.open("Score_file.txt");
    string line;
    for (int i = 0; i<5; i++) {
        if (ifs.is_open(), std::ios_base::app) {
            getline(ifs,line);
            string temp = std::to_string(i+1)+".  "+line;
            scores.push_back(new Text(Point(275,250+(i*50)),temp));
            scores[i]->set_font_size(50);
            scores[i]->set_color(Color::red);
            attach(*scores[i]);
        }
    }
    ifs.close();
}
void high_score_window::back(){
    hide();
    Splash_screen win(Point(100,0),800,675,"Splash Screen");
    gui_main();
}