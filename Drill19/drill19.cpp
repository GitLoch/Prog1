#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct S {
	S(T vv = 0) : val(vv) {}
	T& get();
	const T& get() const;
	void set(T x) { val = x; };
	void operator=(const T& s);
	
	private:
	T val;
};

template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const{
	return val;
}

/*template<typename T>
void S<T>::set(T x){
	val = x;
}*/

template<typename T>
void S<T>::operator=(const T& s){
	val = s;
}

template<typename T>
void read_val(T& v){
	cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	os << "{ ";
	for(int i = 0; i < v.size(); ++i){
		os << v[i] << (i < v.size()-1 ? ", " : " ");
	}
	os << "}";
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	char ch = 0;
	is >> ch;
	if( ch != '{'){
		is.unget();
		return is;
	}
	for(T val; is >> val;){
		v.push_back(val);
		is >> ch;
		if (ch != ',') break;
	}
	
	return is;
}



int main(){
	
	S<int> s;
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {3.2};
	S<std::string> ss {"hello"};
	S<vector<int>> svi {std::vector<int>{1, 1, 2, 3, 5, 8, 8}};

	cout << "S<int> : " << s.get() << endl;	
	cout << "S<int> : " << si.get() << endl;
	cout << "S<char> : " << sc.get() << endl;
	cout << "S<double> : " << sd.get() << endl;
	cout << "S<string> : " << ss.get() << endl;
	//cout << "S<vector<int>> : " << svi.val << endl;
	
	for(auto a: svi.get()){
		cout << a << ' ';
	}
	cout << endl;
	
	si.set(12);
	cout << "S<int> : " << si.get() << endl;
	
	si = 30;
	cout << "S<int> : " << si.get() << endl;
	
	cout << "Please type in an int, a double, a string, and a vector of { int, int, int }. " << endl;
	
	
	int ii;
	read_val(ii);
	S<int> si2{ii};
	
	double dd;
	read_val(dd);
	S<double> sd2{dd};
	
	string str;
	read_val(str);
	S<string> ss2{str};
	
	vector<int> vin;
	read_val(vin);
	S<vector<int>> svi2{vin};
	
	cout << "si2: " << si2.get() << endl;
	cout << "sd2: " << sd2.get() << endl;
	cout << "ss2: " << ss2.get() << endl;
	cout << "svi2: " << svi2.get() << endl;
	
	return 0;
}
