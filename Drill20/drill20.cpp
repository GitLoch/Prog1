#include <iostream>
#include <array>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void printContainer(T& container){
	for(auto& ize : container){
		cout << ize << " ";
	}
	cout << endl;
}

template<typename T>
void addToContainer(T& container, int num){
	for (auto& ize : container){
		ize = ize+num;
	}
}

template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p != e1; ++p){
		*f2++ = *p;
	}
	return f2;
}

template<typename Iter, typename T>
Iter orai_find(Iter first, Iter last, T value)
{
    while(first != last) {
        if (*first == value) {
            return first;
        }
        first++;
    }
    return last;
}

int main(){
try{
	constexpr int size = 10;
	
	int arr[size];
	for (int i = 0; i < size; ++i) arr[i] = i;
	
	array<int, size> ai;
	copy(arr, arr + size, ai.begin());
	vector<int> vi(size);
	copy(arr, arr + size, vi.begin());
	list<int> li(size);
	copy(arr, arr + size, li.begin());
	
	
	
	array<int, size> ai2 = ai;
	vector<int> vi2 = vi;
	list<int> li2 = li;
	
	printContainer(ai);
	printContainer(vi);
	printContainer(li);
	cout << endl;
	
	addToContainer(ai2, 2);
	addToContainer(vi2, 3);
	addToContainer(li2, 5);
	
	printContainer(ai2);
	printContainer(vi2);
	printContainer(li2);
	cout << endl;
	
	orai_copy(ai2.begin(), ai2.end(), vi2.begin());  
	orai_copy(li2.begin(), li2.end(), ai2.begin());
	
	printContainer(ai2);
	printContainer(vi2);
	printContainer(li2);
	cout << endl;
	
	vector<int>::iterator vit;
	vit = orai_find(vi2.begin(), vi2.end(), 3);
	if(vit != vi2.end()){
		cout << "(3) was found at: " << distance(vi2.begin(), vit) << endl;
	}
	else{
		cout << "(3) was not found." << endl;
	}

	vit = orai_find(vi2.begin(), vi2.end(), 27);
	if(vit != vi2.end()){
		cout << "(27) was found at: " << distance(vi2.begin(), vit) << endl;
	}
	else{
		cout << "(27) was not found." << endl;
	}
	
	return 0;
}
catch(exception& e){
	cerr << "Error: " << e.what() << endl;
	return 1;
}
catch(...){
	cerr << "Unexpected error occured." << endl;
	return 2;
}
}
