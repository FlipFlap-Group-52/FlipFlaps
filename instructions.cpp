//  instructions.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "instructions.h"
instructions::instructions(Point xy,int w,int h,const string& s)
:Window(xy,w,h,s),
<<<<<<< HEAD
Instruct(Point(340,150), "Instructions:"),
Long1(Point(100,215),"The purpose of this game is to get all the pancakes to be in order from smallest to biggest."),
Long2(Point(250,245),"You do this by flipping the pancakes."),
Long3(Point(120,275),"The catch is that when you choose a pancake to flip all the pancakes above it flip too."),
Long4(Point(200,305),"Can you get them in the right order before you run out of points?"),
Control_Title(Point(350,400),"Controls:"),
Controls(Point(100, 450), "Use the up and down arrows to get to the pancake you want. Then press the 'Flip' button!"),
Back_box(Point(340,500),90,30),
Back_text(Point(365,520),"BACK"),
behind(Point(0,0),"pancake1.jpg")
=======
Instruct(Point(100,100), "Instructions"),
back_Button(Point(300,50),70,35,"Back",
            [](Address,Address pw){reference_to<instructions>(pw).back();}),
Long(Point(20,300),"The purpose of this game is to get all the pancakes to be in order from biggest to smallest. You do this by flipping the pancakes. The catch is that when you choose a pancake to flip all the pancakes above it flip too. Can you get them in the right order before you run out of points?")
>>>>>>> origin/master
{
	attach(behind);
	Control_Title.set_font_size(20);
	Instruct.set_font_size(20);
	attach(Control_Title);
	attach(Instruct);
<<<<<<< HEAD
	attach(Long1);
	attach(Controls);
	attach(Long2);
	attach(Long3);
	attach(Long4);
	attach(Back_box);
	attach(Back_text);
=======
	attach(Long);
    attach(back_Button);
}

void instructions::back(){
    hide();
    Splash_screen win(Point(100,0),800,675,"Splash Screen");
    gui_main();
>>>>>>> origin/master
}