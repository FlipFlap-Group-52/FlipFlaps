//
//  high_score_window.h
//  
//
//  Created by Jordan Blissett on 4/23/15.
//
//

#ifndef ____high_score_window__
#define ____high_score_window__

#include <stdio.h>
#include "Simple_window.h"
#include "Graph.h"

class high_score_window: public Graph_lib::Window{
public:
    high_score_window(Point xy, int w,int h, const string& s);
	
private:
};
#endif /* defined(____high_score_window__) */