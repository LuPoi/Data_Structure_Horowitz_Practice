#include <iostream>
using namespace std;

void Permutations(char *a, const int k, const int m) {
	if (k == m) {
		for (int i = 0; i <= m; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = k; i <= m; i++) {
			swap(a[k], a[i]);
			Permutations(a, k + 1, m);
			swap(a[k], a[i]);
		}
	}
}

int main() {
	char input[]= {'a','b','c'};
	Permutations(input, 0, 2);
	cout << "origin input after sort is not chaged: ";
	for (int i=0; i <= 2; i++) {
		cout  << input[i] << " ";
	}
	cout << endl;
	return 0;
}
