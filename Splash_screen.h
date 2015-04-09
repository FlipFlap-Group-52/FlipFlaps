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
using namespace Graph_lib;
class Splash_screen : public Graph_lib::Window{
public:
    Splash_screen(Point xy, int w, int h, const string& s);
    
private:
    Button play_button;
    Button score_button;
    Button instructions_button;
    Text title;
	Text team;
    Text name1;
	Text name2;
	Text name3;
	Text button;
	Rectangle play;
	Image background;

    void play();
    void score();
    void instructions();
    
};

#endif /* defined(____Splash_screen__) */
