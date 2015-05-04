//
//  high_score_window.h
//  
//
//  Created by Dakota Cuttrell on 4/23/15.
//
//

#ifndef ____high_score_window__
#define ____high_score_window__

#include <stdio.h>
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Splash_screen.h"
#include "Graph.h"
using namespace Graph_lib;
class high_score_window: public Graph_lib::Window{
public:
	high_score_window(Point xy, int w,int h, const string& s);
    
    void read_score();
    vector<string> sort_scores(vector<string> d,vector<int> x,vector<int> c);
private:
//what is used in high score window
	Text title;
	Text the_winners;
    vector<Text*> scores;
    int scores_num;
    int size;
    string initials;
    vector<int> number;
    vector<int> temp_number;
    vector<string> letters;
    vector<string> temp_letters;
    ofstream ofs;
    ifstream ifs;
	Button back_Button;
    void back();
	

};
#endif /* defined(____high_score_window__) */