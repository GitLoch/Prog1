#include <iostream>
#include <string>
#include <map>
#include <numeric>
#include <stdexcept>

template<typename K, typename V>
void swapmap(const std::map<K, V>& m, std::map<V, K>& n){
	for(std::pair<K, V> a : m){
		n[a.second] = a.first;
		//n.insert(std::make_pair(a.second, a.first));
	}
}

template<typename K>
int summap(const std::map<K, int>& m){
	/*int osszeg = 0;
	for(std::pair<K, int> a : m){
		osszeg+=a.second;
	}*/
	
	int osszeg = std::accumulate(m.begin(), m.end(), 0, [](int sum, const std::pair<std::string, int>& p){ return sum += p.second;});
	return osszeg;
}

void read_map(std::map<std::string, int>& m){
	std::string s;
	int i = 0;
	
	while(m.size()<10){
		std::cin >> s >> i;
		//m[s] = i;
		m.insert(std::make_pair(s, i));
	}	
}

template<typename K, typename V>
void print(const std::map<K,V>& m){
	for(std::pair<K, V> a : m){
		std::cout << a.first << '\t' << a.second << '\n';
	}
}

int main(){
try{
	std::map<std::string, int> msi;
	msi["a"] = 1;
	msi["b"] = 2;
	msi["abc"] = 45;
	msi["x"] = 23;
	msi["g"] = 41;
	msi["wert"] = 92;
	msi["j"] = 30;
	msi["po"] = 11;
	msi["px"] = 67;
	msi["ac"] = 4;
	
	print(msi);
	
	msi.erase("a"); 
	std::cout << "\"a\" kulcsú elem törlése után: " << std::endl;
	print(msi);
	
	msi.erase(msi.begin(), msi.end());
	std::cout << "Teljes törlés után: " << std::endl;
	print(msi);
	
	std::cout << "10 név-érték pár megadása: " << std::endl;
	read_map(msi);
	std::cout << "msi: " << std::endl;
	print(msi);
	
	std::cout << "Msi összeadva: " << summap(msi) << std::endl;
	
	std::map<int, std::string> mis;
	swapmap(msi, mis);
	std::cout << "Mis elemei: " << std::endl;
	print(mis);
	
	return 1;
}
catch(std::exception& e){
	std::cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch(...){
	std::cerr << "Unknown exception." << '\n';
	return 2;
}
}
