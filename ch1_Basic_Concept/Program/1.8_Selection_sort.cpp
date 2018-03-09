#include <iostream>
using namespace std;

// Sort the n integers a[0] to a[n-1] into nondecreasing order.
void SelectionSort(int *a, const int n) {
	for (int i = 0; i < n-1; i++) {
		int j=i;
		// find smallest integer in a[i] to a[n-1]
		for (int k = i+1; k < n; k++) {
			if (a[k] < a[j]) {
				j=k;
			}
		}
		swap(a[i], a[j]);
	}
}

int main() {
	int A[]={1,2,4,1,4,4,2,13,5,23};
	for (int i = 0; i < 10; i++)
		cout << "origin: " << A[i] << endl;

	SelectionSort(A, 10);
	for (int i = 0; i < 10; i++) 
		cout << A[i] << endl;
}
