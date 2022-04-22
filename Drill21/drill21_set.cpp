#include <iostream>
#include <stdexcept>
#include <string>
#include <set>
#include <vector>

struct Fruit{
	std::string name;
	int quantity;
	double unit_price;
	
	Fruit(const std::string& n, int q = 0, double p = 0.0) : name(n), quantity(q), unit_price(p) {}
};

struct Fruit_ptr_cmp{
	bool operator()(const Fruit* a, const Fruit* b){
		return a->name < b->name;
	}
};

int main(){
try{
	std::vector<Fruit> vf {
		Fruit("Plum", 3),
		Fruit("Grape", 33),
		Fruit("Banana", 21),
		Fruit("Apple", 1),
		Fruit("Orange", 19),
		Fruit("Cherry", 98),
		Fruit("Plum", 74),
		Fruit("Kiwi", 54),
	};

	std::cout << "Vector values: " << std::endl;
	for (auto f : vf){
		std::cout << f.name << std::endl;
	}
	std::cout << std::endl;
	
	std::set<Fruit*, Fruit_ptr_cmp> sf;
	
	for(auto& f : vf){
		sf.insert(&f);
	}
	
	std::cout << "Set values: " << std::endl;
	for (auto f : sf){
		std::cout << f->name << std::endl;
	}
	std::cout << std::endl;
}
catch(std::exception& e){
	std::cerr << e.what() << '\n';
	return 1;
}
catch(...){
	std::cerr << "Unexpected error occured.\n";
	return 2;
}
}
