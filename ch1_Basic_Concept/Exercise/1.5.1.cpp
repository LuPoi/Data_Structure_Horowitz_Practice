#include <iostream>
using namespace std;

int HonorRule(int *cof, const int k, const int m, const int x, int result) {
	if (k == m) {
		return cof[m] * x + cof[m+1];
	}
	else {
		return HonorRule(cof, k, m - 1, x, result) * x + cof[m + 1]; // similar to loop, and loop until conditon satisfy
	}
}

int main() {
	// 5x^6 + 3x^2 + 4x + 6
	int input_cof[7] = {5, 0, 0, 0, 3, 4, 6};
	int x;
	cout << "input x: ";
	cin >> x;
	int result = 0;
	result =  HonorRule(input_cof, 0, 5, x, result);
	cout << "result: " << result << endl;
	return 0;
}
