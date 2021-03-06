//
//  Score_window.h
//  
//
//  Created by Jordan Blissett on 4/20/15.
//
//

#ifndef ____Score_window__
#define ____Score_window__

#include <stdio.h>
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "setup_window.h"
#include "high_score_window.h"
using namespace Graph_lib;
class Score_window :public Graph_lib::Window{
public:
    Score_window(Point xy,int w,int h,const string& s,int x,string a);
    void write_score(string s,string t);
    void set_initials(string s);
private:
    Text title;
    string initials;
    ofstream ofs;
    Text* score_text;
    Text* win_lose;
    Text* final_score;
    string score1;
    Button quit_button;
    Button score_button;
    Button replay_button;
    void quit();
    void score();
    void replay();
};
#endif /* defined(____Score_window__) */
