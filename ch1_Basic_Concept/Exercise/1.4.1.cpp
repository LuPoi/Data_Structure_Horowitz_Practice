#include <iostream>
using namespace std;

int DivZero(int a, int b, int c) {
	if (a < 0 && b < 0 && c < 0) {
		throw 1;
	}
	if (a == 0 && b == 0 && c == 0) {
		throw 2;
	}
	if (a <= 0 || b <= 0 || c <= 0) {
		throw "input error";
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

	try {
		DivZero(a, b, c);
	}
	catch(const int e) {
		cerr << "catch exception code: " << e << endl;
		return 0;
	}
	catch(const char* error) {
		cerr << "catch exception: " << error << endl;
		return 0;
	}

	d = DivZero(a, b, c);
	cout << d << endl;
	return 0;
}
