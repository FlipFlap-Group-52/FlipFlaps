//
//  Splash_screen.h
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#ifndef ____Splash_screen__
#define ____Splash_screen__

#include <stdio.h>
#include "Simple_window.h"
#include "Graph.h"
#include "high_score_window.h"
#include "instructions.h"
using namespace Graph_lib;
class Splash_screen : public Graph_lib::Window{
public:
    Splash_screen(Point xy, int w, int h, const string& s);
    //Creates what will be placed on the screen.
private:
//buttons
    Button play_button;
    Button score_button;
    Button instructions_button;
    Text title;
	Text team;
    Text name1;
	Text name2;
	Text name3;
	Text play_text;
	Text score_text;
	Text instructions_text;
	Image background;
	Rectangle play_button_rectangle;
    Rectangle score_button_rectangle;
    Rectangle instructions_button_rectangle;
//for buttons
    void play();
    void score();
    void instructions_cb();
    
};

#endif /* defined(____Splash_screen__) */
