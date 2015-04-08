//Dakota Cuttrell, Ben Anderson, Jordan Blisset

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "setup_window.h"
#include "Splash_screen.h"

int main()
{
	using namespace Graph_lib;
    Splash_screen splash_screen1(Point(100,0),500,500,"Splash Screen");
    splash_screen1.wait_for_button();
    Setup_window win(Point(100,0),500,500,"Difficulty");
	win.wait_for_button();
}