//Dakota Cuttrell, Ben Anderson, Jordan Blisset

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	
	Point tl{100,0};
	Simple_window win{tl,800,675,"Difficulty"};
	
	Text t{Point{310,50},"FlipFlaps"};
	t.set_font_size(50);
	t.set_color(Color::red);
    
    enum difficulty_num {two=2,three,four,five,six,seven,eight,nine};
    Menu difficulty(Point(310,150),50,50,difficulty_num,"Difficulty");
	
	






	win.attach(t);
    win.attach(difficulty);
	win.wait_for_button();
}