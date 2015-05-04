//
//  setup_window.h
//  this will be used for the difficulty buttons and window setup
//
//
//
//

#ifndef ____setup_window__
#define ____setup_window__

#include <stdio.h>
#include "Simple_window.h"
#include "Graph.h"
#include "Pancake.h"
#include "Game_window.h"
#include "Score_window.h"
using namespace Graph_lib;
class Setup_window :public Graph_lib::Window{
public:
    Setup_window(Point xy, int w,int h, const string& s);
   
private:
//menu for diff. options
    Menu diff;
    Text title;
    Text word;
    Text* enter_initials;
    In_box initials;
    Button start;
    Button contin;
    int difficulty;
    string player;
//difficulty choice
    void diff2();
    void diff3();
    void diff4();
    void diff5();
    void diff6();
    void diff7();
    void diff8();
    void diff9();
//buttons
    void start_button();
    void player_initials();
    void continue_button();
    
};
#endif /* defined(____setup_window__) */
