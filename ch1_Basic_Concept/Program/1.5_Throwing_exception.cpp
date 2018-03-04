#include <iostream>
using namespace std;

int DivZero(int a, int b, int c) {
	try {
		if (a <= 0 || b <= 0 || c <= 0) {
			throw "All parameters should be > 0";
		}
	}
	catch(const char* str) { 
		cerr << "錯誤: " << str << endl; 
	}

	return a + b * c + b / c;
}

int main() {
	int a, b, c; int d;
	cout << "a: ";
	cin >> a ;
	cout << "b: ";
	cin >> b ;
	cout << "c: ";
	cin >> c ;
	d = DivZero(a, b, c);
	cout << d << endl;
	return 0;
}
