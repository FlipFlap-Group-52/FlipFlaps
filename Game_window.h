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
        vector<int> perm = perm_pancake(x);
        for (int i=0; i<x; ++i) {
            pancakes.push_back(new Pancake(Point(275-(15*perm[i]),height-(20*i)),250+(30*perm[i]),20));
            height = height-10;
        }
        disp_pancake();
    }
    vector<int> perm_pancake(int x){
        vector<int> dummy;
        for (int i =0; i<x; ++i) {
            dummy.push_back(i);
        }
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(dummy.begin(),dummy.end(),default_random_engine(seed));
        return dummy;
        //disp_pancake(p);
    }
    void disp_pancake(){
        for (int j=0; j<pancakes.size(); ++j) {
            attach(*pancakes[j]);
        }
    }
    void key_press(){
        
    }
    void move_spatula(int movement){
        spatula_height = spatula_height + movement;
    }
    
private:
    Rectangle ground;
    Text title;
    Text level;
    Lines plate;
    Open_polyline spatula;
    vector<Pancake*> pancakes;
    int difficulty;
    int spatula_height;
    int movement;
    string initials;
};


#endif /* defined(____Game_window__) */
