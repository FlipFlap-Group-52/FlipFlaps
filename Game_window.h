//
//  Game_window.h
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#ifndef ____Game_window__
#define ____Game_window__

#include <stdio.h>
#include "Simple_window.h"
#include "Graph.h"
#include "setup_window.h"
#include "Pancake.h"
#include "std_lib_facilities_4.h"
using namespace Graph_lib;
class Game_window :public Graph_lib::Window{
public:
    Game_window(Point xy,int w,int h,const string& s);
    void set_difficulty(int x){
        difficulty=x;
    }
    void set_initials(string s){
        initials = s;
    }
    
private:
    Rectangle ground;
    Text title;
    Text level;
    Lines plate;
    Open_polyline spatula;
    vector<Pancake*> pancakes;
    int difficulty;
    string initials;
};


#endif /* defined(____Game_window__) */
