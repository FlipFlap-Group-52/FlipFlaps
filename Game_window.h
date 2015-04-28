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
#include "find_solution.h"
#include "std_lib_facilities_4.h"
using namespace Graph_lib;
class Game_window :public Graph_lib::Window{
public:
    Game_window(Point xy,int w,int h,const string& s,int x,string s);
    void set_difficulty(int x);
    void set_initials(string s);
    void create_pancake(int x);
    vector<int> perm_pancake(int x);
    void disp_pancake();
    int handle(int e);
    
    void move_spatula(int movement);
    void create_spatula();
    void flip(int pos);
    void solution();
    void solution_score();
private:
    Text title;
    Text score;
    Button flip_button;
    Lines plate;
    Open_polyline* spatula;
    Text* level;
    Text* score_out;
    Text* flip_out;
    Text* done_in_x_flips;
    vector<Pancake*> pancakes;
    vector<int> perm;
    vector<int> dummy;
    vector<int> sorted;
    vector<int>* solution_vec;
    int difficulty;
    int spatula_height;
    int movement;
    string initials;
    int game_won = 0;
    int spatula_level=0;
    int flip_count;
    int scoring;
    int solution_num;
    void Flip();
};


#endif /* defined(____Game_window__) */
