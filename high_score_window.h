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
#include "Graph.h"
using namespace Graph_lib;
class high_score_window: public Graph_lib::Window{
public:
	high_score_window(Point xy, int w,int h, const string& s);
    
    void write_score(string s,string t){}
    void read_score(){}
private:
	Text title;
	Text the_winners;
    ofstream ofs;
    ifstream ifs;
	

};
#endif /* defined(____high_score_window__) */