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
    Game_window(Point xy,int w,int h,const string& s,int x);
    void set_difficulty(int x){
        difficulty=x;
    }
    void set_initials(string s){
        initials = s;
    }
    void create_pancake(int x){
        int height = 570;
        for (int i=0; i<x; ++i) {
            pancakes.push_back(new Pancake(Point(275-(15*i),height-(20*i)),250+(30*i),20));
            height = height-10;
        }
        perm_pancake(pancakes);
         
    }
    void perm_pancake(vector<Pancake*> p){
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(p.begin(),p.end(),default_random_engine(seed));
        disp_pancake(p);
    }
    void disp_pancake(vector<Pancake*> p){
        for (int j=0; j<p.size(); ++j) {
            attach(*p[j]);
        }
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
