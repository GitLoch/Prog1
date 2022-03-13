#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"
#include <string>
#include <iostream>

using namespace Graph_lib;

double one(double x){ 
	return 1; 
}

int main(){
	Simple_window win{Point(200, 200), 600, 600, "Function graphs."};	
	win.wait_for_button();
	
	Axis xa {Axis::x, Point{100, 300}, 400, 20, "1 = = 20 pixels"};
	Axis ya {Axis::y, Point{300, 500}, 400, 20, "1 = = 20 pixels"};
	win.attach(xa);
	win.attach(ya);
	win.wait_for_button();
	
	Function elso { [](double x){return (double)1;}, -10, 11, Point(300, 300), 400, 20, 20};
	win.attach(elso);
	win.wait_for_button();
	
	Function masodik { [](double x){return x/2;}, -10, 11, Point(300, 300), 400, 20, 20};
	win.attach(masodik);
	Text t {Point(150, 350), "x/2"};
	win.attach(t);
	win.wait_for_button();
	
	Function harmadik { [](double x) { return x*x; }, -10, 11, Point(300,300), 400, 20, 20};
	win.attach(harmadik);
	win.wait_for_button();
	
	Function negyedik { cos, -10, 11, Point(300,300), 400, 20, 20};
	negyedik.set_color(Color::blue);
	win.attach(negyedik);
	win.wait_for_button();
	
	Function otodik { [](double x) {return cos(x/2);}, -10, 11, Point(300,300), 400, 20, 20};
	win.attach(otodik);
	win.wait_for_button();
	
	return 0;
}
