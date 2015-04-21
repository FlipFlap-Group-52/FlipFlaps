//
//  Score_window.h
//  
//
//  Created by Jordan Blissett on 4/20/15.
//
//

#ifndef ____Score_window__
#define ____Score_window__

#include <stdio.h>
#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "setup_window.h"
using namespace Graph_lib;
class Score_window :public Graph_lib::Window{
public:
    Score_window(Point xy,int w,int h,const string& s);
    
private:
    Text title;
    Text score;
    Button quit_button;
    Button replay_button;
    void quit();
    void replay();
};
#endif /* defined(____Score_window__) */
