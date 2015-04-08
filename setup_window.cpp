//
//  setup_window.cpp
//  
//
//  Created by Jordan Blissett on 4/8/15.
//
//

#include "setup_window.h"
Setup_window::Setup_window(Point xy,int w,int h,const string& s)
:Simple_window(xy,w,h,s),
diff(Point(70,40),70,20,Menu::vertical,"Difficulty"),
title(Point(300,50),"FlipFlaps")
{
    diff.attach(new Button(Point(0,0),0,0,"2",cb_diff2));
    diff.attach(new Button(Point(0,0),0,0,"3",cb_diff3));
    diff.attach(new Button(Point(0,0),0,0,"4",cb_diff4));
    diff.attach(new Button(Point(0,0),0,0,"5",cb_diff5));
    diff.attach(new Button(Point(0,0),0,0,"6",cb_diff6));
    diff.attach(new Button(Point(0,0),0,0,"7",cb_diff7));
    diff.attach(new Button(Point(0,0),0,0,"8",cb_diff8));
    diff.attach(new Button(Point(0,0),0,0,"9",cb_diff9));
    attach(diff);
    title.set_font_size(50);
    title.set_color(Color::red);
    attach(title);

}

void Setup_window::cb_diff2(Address,Address pw){
    reference_to<Setup_window>(pw).diff2();
}
void Setup_window::diff2(){
    
}
void Setup_window::cb_diff3(Address,Address pw){
    reference_to<Setup_window>(pw).diff3();
}
void Setup_window::diff3(){
    
}
void Setup_window::cb_diff4(Address,Address pw){
    reference_to<Setup_window>(pw).diff4();
}
void Setup_window::diff4(){
    
}
void Setup_window::cb_diff5(Address,Address pw){
    reference_to<Setup_window>(pw).diff5();
}
void Setup_window::diff5(){
    
}
void Setup_window::cb_diff6(Address,Address pw){
    reference_to<Setup_window>(pw).diff6();
}
void Setup_window::diff6(){
    
}
void Setup_window::cb_diff7(Address,Address pw){
    reference_to<Setup_window>(pw).diff7();
}
void Setup_window::diff7(){
    
}
void Setup_window::cb_diff8(Address,Address pw){
    reference_to<Setup_window>(pw).diff8();
}
void Setup_window::diff8(){
    
}
void Setup_window::cb_diff9(Address,Address pw){
    reference_to<Setup_window>(pw).diff9();
}
void Setup_window::diff9(){
    
}
