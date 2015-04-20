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
        perm = perm_pancake(x);
        for (int i=0; i<x; ++i) {
            pancakes.push_back(new Pancake(Point(275-(15*perm[i]),height-(20*i)),250+(30*perm[i]),20));
            height = height-10;
        }
        disp_pancake();
    }
    vector<int> perm_pancake(int x){
        for (int i =0; i<x; ++i) {
            dummy.push_back(i);
            sorted.push_back(i);
        }
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(dummy.begin(),dummy.end(),default_random_engine(seed));
        reverse(sorted.begin(),sorted.end());
        
        return dummy;
    }
    void disp_pancake(){
        for (int j=0; j<pancakes.size(); ++j) {
            attach(*pancakes[j]);
        }
    }
    int handle(int e) {
        switch(e)
        {
            case FL_FOCUS:
            case FL_UNFOCUS:
                return 1;
            case FL_KEYBOARD:
                int key = Fl::event_key();
                if (spatula_level==0 && spatula_level!=pancakes.size()-2) {
                    switch(key)
                    {
                        case FL_Up:
                            spatula_level=spatula_level + 1;
                            detach(*spatula);
                            move_spatula(-30);
                            redraw();
                            return 1;
                    }
                }
                if (spatula_level<pancakes.size()-2 && spatula_level>0) {
                    switch(key)
                    {
                        case FL_Up:
                            spatula_level=spatula_level + 1;
                            detach(*spatula);
                            move_spatula(-30);
                            redraw();
                            return 1;
                        case FL_Down:
                            spatula_level=spatula_level - 1;
                            detach(*spatula);
                            move_spatula(30);
                            redraw();
                            return 1;
                    }
                }
                if (spatula_level == pancakes.size()-2 && spatula_level!=0) {
                    switch(key)
                    {
                        case FL_Down:
                            spatula_level=spatula_level - 1;
                            detach(*spatula);
                            move_spatula(30);
                            redraw();
                            return 1;
                    }
                }
            }
        return Fl_Window::handle(e);
    }
    
    void move_spatula(int movement){
        spatula_height = spatula_height + movement;
        create_spatula();
    }
    void create_spatula(){
        spatula = new Open_polyline;
        spatula->add(Point(0,spatula_height));
        spatula->add(Point(175,spatula_height));
        spatula->add(Point(200,spatula_height+24));
        spatula->add(Point(550,spatula_height+24));
        spatula->set_color(Color::black);
        spatula->set_style(Line_style(Line_style::solid, 5));
        attach(*spatula);
    }
    void flip(int pos){
        for (int j=0; j<pancakes.size(); ++j) {
            detach(*pancakes[j]);
        }
        pancakes.clear();
        reverse(perm.begin()+pos,perm.end());
        int height = 570;
        for (int i=0; i<difficulty; ++i) {
            pancakes.push_back(new Pancake(Point(275-(15*perm[i]),height-(20*i)),250+(30*perm[i]),20));
            height = height-10;
        }
        disp_pancake();
    }
private:
    Rectangle ground;
    Text title;
    Button flip_button;
    Text level;
    Lines plate;
    Open_polyline* spatula;
    vector<Pancake*> pancakes;
    vector<int> perm;
    vector<int> dummy;
    vector<int> sorted;
    int difficulty;
    int spatula_height;
    int movement;
    string initials;
    int game_won = 0;
    int spatula_level=0;
    void Flip();
};


#endif /* defined(____Game_window__) */
