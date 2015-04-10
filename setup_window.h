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
using namespace Graph_lib;
class Setup_window :public Graph_lib::Window{
public:
    Setup_window(Point xy, int w,int h, const string& s);
   
private:
    Menu diff;
    Text title;
	Text word;
    In_box initials;
    Button start;
    int difficulty;
    void diff2();
    void diff3();
    void diff4();
    void diff5();
    void diff6();
    void diff7();
    void diff8();
    void diff9();
    void start_button();
    void player_initials();
    
};
#endif /* defined(____setup_window__) */
