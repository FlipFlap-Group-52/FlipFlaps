//Dakota Cuttrell, Ben Anderson, Jordan Blisset

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "setup_window.h"
#include "Splash_screen.h"
#include "Game_window.h"
#include "GUI.h"
using namespace Graph_lib;
int main()
{
    Splash_screen splash_screen1(Point(100,0),800,675,"Splash Screen");
    return gui_main();
    //Setup_window win(Point(100,0),800,675,"Difficulty");
    //return gui_main();
    //Game_window game_win(Point(100,0),800,675,"FlipFlap");
    //return gui_main();
}