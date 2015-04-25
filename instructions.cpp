//  instructions.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "instructions.h"
#include "setup_window.h"
instructions::instructions(Point xy,int w,int h,const string& s)
:Window(xy,w,h,s),
Instruct(Point(100,100), "Instructions"),
Long(Point(20,300),"The purpose of this game is to get all the pancakes to be in order from smallest to biggest. You do this by flipping the pancakes. The catch is that when you choose a pancake to flip all the pancakes above it flip too. Can you get them in the right order before you run out of points?")
{
	attach(Instruct);
	attach(Long);
}