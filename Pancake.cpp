//
//  Pancake.cpp
//  
//
//  Created by Jordan Blissett on 4/9/15.
//
//

#include "Pancake.h"

Pancake::Pancake(Point xy,int w,int h,int x)
:Rectangle(xy,w,h)
{
    vector<Pancake> pancakes;
    pancakes.push_back(Pancake(Point(275,570),250,20,x));
    for (int i = 1; i<=x; ++i) {
        pancakes.push_back(Pancake(Point(275-(20*i),570-(20*i)),250+(20*i),20,x));
    }
        
}