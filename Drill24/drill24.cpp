#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main(){
try{
	cout << "sizeof:\n";
	cout << "char:\t\t" << sizeof(char) << "\n";
	cout << "short:\t\t" << sizeof(short) << "\n";
	cout << "int:\t\t" << sizeof(int) << "\n";
	cout << "long:\t\t" << sizeof(long) << "\n";
	cout << "float:\t\t" << sizeof(float) << "\n";
	cout << "double:\t\t" << sizeof(double) << "\n";
	cout << "int*:\t\t" << sizeof(int*) << "\n";
	cout << "double*:\t" << sizeof(double*) << "\n";
	cout << "float*:\t\t" << sizeof(float*) << "\n";
	cout << "long*:\t\t" << sizeof(long*) << "\n\n";
	
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10,10);
	Matrix<int,3> e(10,10,10);
	
	cout << "Matrix sizes:\n";
	cout << "1D int, 10 elements: \t\t\t" << sizeof(a) << '\n';
	cout << "1D int, 100 elements: \t\t\t" << sizeof(b) << '\n';
	cout << "1D double, 10 elements: \t\t" << sizeof(c) << '\n';
	cout << "2D int, 100 elements: \t\t\t" << sizeof(d) << '\n';
	cout << "3D int, 1000 elements: \t\t\t" << sizeof(e) << '\n';
	
	cout << "\nNumber of elements:\n";
	cout << "a:\t" << a.size() << "\n";
	cout << "b:\t" << b.size() << "\n";
	cout << "c:\t" << c.size() << "\n";
	cout << "d:\t" << d.size() << "\n";
	cout << "e:\t" << e.size() << "\n";
	
	
	
	cout << "\nEnter numbers:\n";
	int x;
	while(cin >> x){
		/*errno = 0;
		double y = sqrt(x);
		if (errno == EDOM){*/
		double y = sqrt(x);
		if (y > 0){
			cout << y << "\n";			
		}
		else{
			cout << "No square root.\n";
		}
	}
	
	
	
	cin.clear();
	cin.ignore();
	cout << "\nEnter 10 floating point values:\n";
	Matrix<double> m2(10);
	double d2;
	for(int i = 0; i < m2.size(); ++i){
		cin >> d2;
		if(!cin) throw runtime_error("Problem reading from cin.");
		m2[i] = d2;
	}
	cout << "Matrix:\n" << m2 << '\n';
	
	
	
	cout << "\nMultiplication table\nEnter n: ";
	int n;
	cin >> n;
	cout << "Enter m: ";
	int m3;
	cin >> m3;
	Matrix<int, 2> mtable(n, m3);
	
	//Index: a long egy átnevezése
	//typedef long Index;
	for(int i = 0; i < mtable.dim1(); ++i){
		for(int j = 0; j < mtable.dim2(); ++j){
			mtable(i, j) = (i+1)*(j+1);
			cout << setw(5) << mtable(i, j);
		}
		cout << '\n';
	}
	
	
	Matrix<complex<double>> m4(10);
	cout << "\nEnter 10 complex numbers (Re, Im):\n";
	complex<double> comp;
	for(int i = 0; i < 10; ++i){
		cin >> comp;
		if(!cin) throw runtime_error("Problem reading complex.");
		m4[i] = comp;
	}
	cout << "Complex matrix: " << m4 << '\n';
	complex<double> sum;
	for(Index i=0; i<m4.size(); ++i){
		sum+= m4[i];
	}
	cout << "Sum: " << sum << '\n';

	Matrix<int,2> m5(2,3);
	cout << "\nEnter 6 ints: \n";
	for(int i = 0; i < m5.dim1(); ++i){
		for(int j = 0; j < m5.dim2(); ++j){
			cin >> m5(i, j);
		}
	}
	cout << m5;
	
	return 0;
} catch(exception& e){
	cerr << "Exception: " << e.what() << endl;
	return 1;
} catch(...){
	cerr << "Unexpected error." << endl;
	return 2;
}
}
