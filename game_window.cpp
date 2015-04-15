//
//  Game_window.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "Game_window.h"
Game_window::Game_window(Point xy,int w,int h,const string& s,int x)
:Window(xy,w,h,s),
ground(Point(0,350),800,325),
title(Point(310,50),"FlipFlaps"),
level(Point(550,75),"Level")
{
    ground.set_fill_color(Color::green);
    //attach(ground);
    title.set_font_size(50);
    title.set_color(Color::red);
    attach(title);
    level.set_font_size(50);
    level.set_color(Color::red);
    attach(level);
    plate.add(Point(275,600),Point(525,600));
    plate.set_style(Line_style(Line_style::solid, 5));
    attach(plate);
    spatula_height = 570;
    spatula.add(Point(0,spatula_height));
    spatula.add(Point(175,spatula_height));
    spatula.add(Point(200,spatula_height+24));
    spatula.add(Point(550,spatula_height+24));
    spatula.set_style(Line_style(Line_style::solid, 5));
    attach(spatula);
    create_pancake(x);
   
}