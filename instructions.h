//
//  instructions.h
//  
//
//  Created by Benjamin Anderson on 4/25/15.
//
//

#ifndef ____instructions__
#define ____instructions__

#include <stdio.h>
#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;
class instructions : public Graph_lib::Window{
public:
    instructions(Point xy, int w, int h, const string& s);
	
	private:
	Text Instruct;
	Text Long;
	
	
};
	#endif /* defined(____instructions__) */