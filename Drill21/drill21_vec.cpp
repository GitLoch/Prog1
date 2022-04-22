#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

struct Item{
	Item(string a, int b, double c) : name(a), iid(b), value(c) {};
	Item(){};

	string name;
	int iid;
	double value;
};

istream& operator>>(istream& is, Item& d){
	return is >> d.name >> d.iid >> d.value;
}

template<typename Iter>
void print(Iter begin, Iter end){
	while(begin != end){
		cout << begin->name << "     \t" << begin->iid << "\t\t" << begin->value << endl;
		begin++;
	}
}

bool nevszerint(Item a, Item b){
	return a.name < b.name;
}

bool iidszerint(Item a, Item b){
	return a.iid < b.iid;
}

bool valueszerintdesc(Item a, Item b){
	return a.value > b.value;
}

template<typename T>
void RemoveByName(T& container, string nameToRemove){
	container.erase(remove_if(container.begin(), container.end(), [=](Item item) { return item.name == nameToRemove; }), container.end());
}

template<typename T>
void RemoveByIid(T& container, int iidToRemove){
	container.erase(remove_if(container.begin(), container.end(), [=](Item item) { return item.iid == iidToRemove; }), container.end());
}

int main(){
try{
	vector<Item> vi;
	ifstream ifs {"input_items.txt"};
	if (!ifs){
		throw runtime_error("Could not read from file."); 
	}
	for(Item d; ifs >> d;){
		vi.push_back(d);
	}
	ifs.close();
	cout << "Az elemek:" << endl;
	print(vi.begin(), vi.end());

	sort(vi.begin(), vi.end(), nevszerint);
	cout << "\nNév szerint sorrendben:" << endl;
	print(vi.begin(), vi.end());

	sort(vi.begin(), vi.end(), iidszerint);
	cout << "\nIid szerint sorrendben:" << endl;
	print(vi.begin(), vi.end());

	sort(vi.begin(), vi.end(), valueszerintdesc);
	cout << "\nValue szerint sorrendben (desc):" << endl;
	print(vi.begin(), vi.end());

	Item d("horse shoe",99,12.34);
	vi.insert(vi.end(), d);
	Item e("Canon S400",9988,499.95);
	vi.insert(vi.end(), e);
	cout << "\nAz elemek:" << endl;
	print(vi.begin(), vi.end());

	RemoveByName(vi, "asanyi");
	RemoveByName(vi, "viego");
	cout << "\nAz elemek:" << endl;
	print(vi.begin(), vi.end());

	RemoveByIid(vi, 99);
	RemoveByIid(vi, 6);
	cout << "\nAz elemek:" << endl;
	print(vi.begin(), vi.end());

	cout << "\n---------------------" << endl;
	//////////////////////////////////////////////////////

	list<Item> li;
	ifstream iifs {"input_items.txt"};
	for(Item d; iifs >> d;){
		li.push_back(d);
	}
	iifs.close();
	cout << "\nAz elemek:" << endl;
	print(li.begin(), li.end());

	li.sort(nevszerint);
	cout << "\nNév szerint sorrendben:" << endl;
	print(li.begin(), li.end());

	li.sort(iidszerint);
	cout << "\nIid szerint sorrendben:" << endl;
	print(li.begin(), li.end());

	li.sort(valueszerintdesc);
	cout << "\nValue szerint sorrendben (desc):" << endl;
	print(li.begin(), li.end());

	li.insert(li.end(), d);
	li.insert(li.end(), e);
	cout << "\nAz elemek:" << endl;
	print(li.begin(), li.end());

	RemoveByName(li, "asanyi");
	RemoveByName(li, "viego");
	cout << "\nAz elemek:" << endl;
	print(li.begin(), li.end());

	RemoveByIid(li, 99);
	RemoveByIid(li, 6);
	cout << "\nAz elemek:" << endl;
	print(li.begin(), li.end());

	return 0;
}
catch(exception& e){
	cerr << "Exception: " << e.what() << endl;
	return 1;
}
catch(...){
	cerr << "Unknown exception occured." << endl;
	return 2;
}
}
