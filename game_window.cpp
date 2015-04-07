#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"

int main()
try {
    if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
                             H112);
    //Create window
    Simple_window game_win(Point(100,0),800,675,"FlipFlap");
    
    //background 1
    Rectangle ground(Point(0,350),800,325);
    ground.set_fill_color(Color::green);
    
    
    //title
    Text title(Point(310,50),"FlipFlaps");
    title.set_font_size(50);
    title.set_color(Color::red);
    
    //level
    Text level(Point(550,75),"Level");
    level.set_font_size(50);
    level.set_color(Color::red);
    
    //plate
    Lines plate;
    plate.add(Point(275,600),Point(525,600));
    plate.set_style(Line_style(Line_style::solid, 5));
    
    //spatula
    Open_polyline spatula;
    spatula.add(Point(0,550));
    spatula.add(Point(175,550));
    spatula.add(Point(200,575));
    spatula.add(Point(550,575));
    spatula.set_style(Line_style(Line_style::solid, 5));
    
    //attachments
    hide(next_button);
    game_win.attach(ground);
    game_win.attach(title);
    game_win.attach(level);
    game_win.attach(plate);
    game_win.attach(spatula);
    game_win.wait_for_button();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
    }
    catch (...) {
        cerr << "Some exception\n";
        return 2;
    }
