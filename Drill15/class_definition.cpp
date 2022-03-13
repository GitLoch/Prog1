#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person{
	public:
		Person(){}
		//Person(string n, int a) : n(n), a(a) {
		Person(string f, string l, int a): f(f), l(l), a(a) {
			if(a < 0 || a >= 150 ){
				throw runtime_error ("Invalid age.");
			}
			
			string n = f + l;
			char t[14] = {';', ':', '\"', '\'', '[', ']', '*', '&', '^', '%', '$', '#', '@', '!'};
			for (int i = 0; i < n.length(); i++){
				//; : " ' [ ] * & ^ % $ # @ !
				for (int j = 0; j < (sizeof(t)/sizeof(t[0])); j++){
					if (n[i] == t[j]){
						throw runtime_error ("Invalid name.");
					}
				}
			}
		}
		//string name() const { return n; }
		
		string first() const {
			return f;
			}
			
		string last() const {
			return l;
		}
		
		int age() const {
			return a;
		}
	
	private:
		//string n;
		string f;
		string l;
		int a;
};

ostream& operator<<(ostream& os, const Person& p){
	return os << p.first() << " " << p.last() << " " << p.age();
}

istream& operator>>(istream& is, Person& p){
	string f;
	string l;
	int a;
	is >> f >> l >> a;
	
	p = Person(f, l, a);
	return is;
}

int main(){
	//Person p;
	Person p = Person("Goofy", "a", 63);
	//p.name = "Goofy";
	//p.age = 63;
	cout << p.first() << " " << p.last() << " " << p.age() << endl;
	
	
	Person a;
	cin >> a;
	cout << a << endl;
	
	vector<Person> vec;
	for(Person p; cin >> p;){ //while(cin>>p);
		if(p.first() == "end") break;
		vec.push_back(p);
	}
	
	for(Person p: vec){
		cout << p << endl;
	}	
	
	return 0;
}
