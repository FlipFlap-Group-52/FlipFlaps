//Dakota Cuttrell, Ben Anderson, Jordan Blisset

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "setup_window.h"

int main()
{
	using namespace Graph_lib;
    Setup_window win(Point(100,0),500,500,"Difficulty");
	win.wait_for_button();
}