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
class Splash_screen : public Simple_window{
public:
    Splash_screen(Point xy, int w, int h, const string& s);
    
private:
    Button play_button;
    Button score_button;
    Button instructions_button;
    static void cb_play(Address,Address);
    void play();
    static void cb_score(Address,Address);
    void score();
    static void cb_instructions(Address,Address);
    void instructions();
    
};

#endif /* defined(____Splash_screen__) */
