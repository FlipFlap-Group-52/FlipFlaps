//
//  high_score_window.cpp
//  
//
//  Created by Dakota Cuttrell on 4/23/15.
//
//

#include "high_score_window.h"
//initializing the window, texts and button

high_score_window::high_score_window(Point xy,int w,int h,const string& s)
:Window(xy,w,h,s),
title(Point(310,50),"FlipFlaps"),
the_winners(Point(250,150),"Top 5 Scores!"),
back_Button(Point(100,50),70,35,"Back",
            [](Address,Address pw){reference_to<high_score_window>(pw).back();})
{
//Attachments to window

    title.set_font_size(50);
    the_winners.set_font_size(50);
    title.set_color(Color::red);
    the_winners.set_color(Color::blue);
    attach(title);
    attach(the_winners);
	attach(back_Button);
    read_score();

}
//printing out scores onto window

void high_score_window::read_score(){
    ifs.open("Score_file.txt");
    string line;
    if (ifs.is_open(), std::ios_base::app) {
        while (ifs>>initials>>scores_num) {
            number.push_back(scores_num);
            temp_number.push_back(scores_num);
            temp_letters.push_back(initials);
        }
    }
    
    sort(temp_number.begin(),temp_number.end());
    reverse(temp_number.begin(),temp_number.end());
    sort_scores(temp_letters,number,temp_number);
    if (number.size()>=5) {
        size=5;
    }
    else{
        size=number.size();
    }
    for (int i = 0; i<size; i++) {
        string temp = std::to_string(i+1)+".  "+letters[i]+"   "+std::to_string(temp_number[i]);
        scores.push_back(new Text(Point(275,250+(i*50)),temp));
        scores[i]->set_font_size(50);
        scores[i]->set_color(Color::red);
        attach(*scores[i]);
    }
    ifs.close();
}
vector<string> high_score_window::sort_scores(vector<string> d,vector<int> x,vector<int> c){
    for (int i = 0; i<c.size(); i++) {
        for (int j = 0; j<c.size(); j++) {
            if (c[i] == x[j]) {
                letters.push_back(d[j]);
            }

        }
        
    }
    return letters;
}
    

//takes you back to splash screen
void high_score_window::back(){
    hide();
    Splash_screen win(Point(100,0),800,675,"Splash Screen");
    gui_main();
}