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
        solution();
        for (int i=0; i<x; ++i) {
            pancakes.push_back(new Pancake(Point(300-(15*perm[i]),height-(20*i)),200+(30*perm[i]),20));
            height = height-10;
            //cout<<perm[i];
        }
        disp_pancake();
    }
    vector<int> perm_pancake(int x){
        for (int i =1; i<=x; ++i) {
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
        spatula->add(Point(140,spatula_height));
        spatula->add(Point(165,spatula_height+24));
        spatula->add(Point(600,spatula_height+24));
        spatula->set_color(Color::black);
        spatula->set_style(Line_style(Line_style::solid, 5));
        attach(*spatula);
    }
    void flip(int pos){
        flip_count = flip_count +1;
        solution_score();
        for (int j=0; j<pancakes.size(); ++j) {
            detach(*pancakes[j]);
        }
        pancakes.clear();
        reverse(perm.begin()+pos,perm.end());
        int height = 570;
        for (int i=0; i<difficulty; ++i) {
            pancakes.push_back(new Pancake(Point(300-(15*perm[i]),height-(20*i)),200+(30*perm[i]),20));
            height = height-10;
        }
        //solution_score();
        disp_pancake();
    }
    void solution(){
        reverse(perm.begin(),perm.end());
        solution_vec = find_solution(perm);
        solution_num = solution_vec->size();
        if (solution_num == 0) {
            perm_pancake(difficulty);
            solution();
        }
        //cout<<"solution: " <<solution_num<< " ";
        reverse(perm.begin(),perm.end());
    }
    void solution_score(){
        if (flip_count <= solution_num) {
            scoring = 100 * difficulty;
        }
        else{
        scoring = (100-10*(flip_count-solution_num))*difficulty;
        //cout<<"score: "<< scoring<< " ";
        }
        detach(*score_out);
        string temp = std::to_string(scoring);
        score_out = new Text(Point(320,210),temp.c_str());
        score_out->set_font_size(100);
        score_out->set_color(Color::red);
        attach(*score_out);
        
    }
private:
    //Rectangle ground;
    Text title;
    Text score;
    Button flip_button;
    Lines plate;
    Open_polyline* spatula;
    Text* level;
    Text* score_out;
    Text* flip_out;
    Text* done_in_x_flips;
    //Text diff;
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
