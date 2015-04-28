//
//  high_score_window.cpp
//  
//
//  Created by Dakota Cuttrell on 4/23/15.
//
//

#include "high_score_window.h"

high_score_window::high_score_window(Point xy,int w,int h,const string& s)
:Window(xy,w,h,s),
title(Point(310,50),"FlipFlaps"),
the_winners(Point(250,150),"Top 5 Scores")
{

    title.set_font_size(50);
    the_winners.set_font_size(50);
    title.set_color(Color::red);
    the_winners.set_color(Color::blue);
    attach(title);
    attach(the_winners);


}