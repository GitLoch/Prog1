#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"

#include <iostream>
#include <string>
#include <vector>

using namespace Graph_lib;

int main(){
	try {
		Point t1(300, 50);
		Simple_window win(t1, 1000, 800, "A Window");
		win.wait_for_button();

		/////////////////////

		Lines lines;
		int size = 800;
		for (int i = 100; i < size; i+=100){
			lines.add(Point(i, 0), Point(i, size));
			lines.add(Point(0, i), Point(size, i));
		}
		win.attach(lines);
		win.wait_for_button();

		/////////////////////

		Vector_ref<Rectangle> v;
		for (int i = 0; i<8; i++){
			v.push_back(new Rectangle(Point(i*100, i*100), 100, 100));
			v[v.size()-1].set_fill_color(Color::red);
			win.attach(v[v.size()-1]);
		}
		win.wait_for_button();

		/////////////////////

		Image egy (Point(200,0), "300.jpg");
		egy.set_mask(Point(0, 0), 200, 200);
		win.attach(egy);
		Image ketto (Point(0,200), "300.jpg");
		ketto.set_mask(Point(0, 0), 200, 200);
		win.attach(ketto);
		Image harom (Point(400,200), "300.jpg");
		harom.set_mask(Point(0, 0), 200, 200);
		win.attach(harom);

		//Ezt azért raktam ide mert valamiért ez megváltoztatta a labelt 300.jpg-re.
		win.set_label("A Window");

		win.wait_for_button();

		//////////////////////

		
		srand(time(0));
		while(true){
			int xkoor = rand() % 7;
			int ykoor = rand() % 7;

			Image randomimage (Point(xkoor*100, ykoor*100), "100.jpg");
			win.attach(randomimage);
			
			//Valamiért emiatt a label egy csomó értelmetlen karakterré vált.
			win.set_label("A Window");

			win.wait_for_button();
		}
		return 0;
	}
	catch (exception& e){
		cerr << "Error:" << e.what() << endl;
		return 1;
	}
	catch (...){
		cerr << "Unhandled exception." << endl;
		return 2;
	}
}
