//
//  setup_window.h
//  this will be used for the difficulty buttons and window setup
//
//
//
//

#ifndef ____setup_window__
#define ____setup_window__

#include <stdio.h>
#include "Simple_window.h"
#include "Graph.h"
using namespace Graph_lib;
class Setup_window :public Simple_window{
public:
    Setup_window(Point xy, int w,int h, const string& s);
   
private:
    Menu diff;
    static void cb_diff2(Address,Address);
    void diff2();
    static void cb_diff3(Address,Address);
    void diff3();
    static void cb_diff4(Address,Address);
    void diff4();
    static void cb_diff5(Address,Address);
    void diff5();
    static void cb_diff6(Address,Address);
    void diff6();
    static void cb_diff7(Address,Address);
    void diff7();
    static void cb_diff8(Address,Address);
    void diff8();
    static void cb_diff9(Address,Address);
    void diff9();
    
};
#endif /* defined(____setup_window__) */
