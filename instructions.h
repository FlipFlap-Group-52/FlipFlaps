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
#include "Splash_screen.h"
using namespace Graph_lib;
class instructions : public Graph_lib::Window{
public:
    instructions(Point xy, int w, int h, const string& s);
	//what is used in instructions.cpp
	private:
	Text Instruct;
	Text Long1;
	Text Long2;
	Text Long3;
	Text Long4;
	Text Controls;
	Text Control_Title;
	Image behind;
	Text Back_text;
	Rectangle Back_box;
    //added back button
    Button back_Button;
    void back();
	
	
};
	#endif /* defined(____instructions__) */