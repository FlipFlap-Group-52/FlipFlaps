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
the_winners(Point(250,150),"Top 5 Scores"),
back_Button(Point(300,50),70,35,"Back",
            [](Address,Address pw){reference_to<high_score_window>(pw).back();})
{

    title.set_font_size(50);
    the_winners.set_font_size(50);
    title.set_color(Color::red);
    the_winners.set_color(Color::blue);
    attach(title);
    attach(the_winners);
	attach(back_Button);
}
void high_score_window::write_score(string s,string t){
    ofs.open("Score_file.txt");
    if (ofs.is_open()) {
        ofs<< s << "   " << t;
        ofs.close();
    }
}
void high_score_window::read_score(){
    ifs.open("Score_file.txt");
    if (ifs.is_open()) {
       
    }
}
void high_score_window::back(){
    hide();
    Splash_screen win(Point(100,0),800,675,"Splash Screen");
    gui_main();
}