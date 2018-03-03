#include <iostream>
using namespace std;

int Max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

void Nothing(void) {
	cout << "Enter void function" << endl;
	cout << "Exit void function" << endl;
	return;
}

int main() {
	int a = 5;
	int b = 2;
	int result = Max(a,b);
	Nothing();
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "Max result: " << result << endl;
	return 0;
}
