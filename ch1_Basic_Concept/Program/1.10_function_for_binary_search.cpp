#include <iostream>
using namespace std;

int BinarySearch(int *a, const int x, const int n) {
	int left = 0;
	int right = n-1;

	while (left <= right && a[left] <= x <= a[right]) {
		int middle = (left + right) / 2;
		cout << "left: " << left << endl;
		cout << "right: " << right << endl;
		cout << "middle: " << middle << endl;
		if (x < a[middle]) {
			right = middle - 1;
		}
		else if (x > a[middle]) {
			left = middle + 1;
		}
		else {
			return middle;
		}
	}
	return -1;
}

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

	int search_number;
	cout << "input search number: ";
	cin >> search_number;
	int result = BinarySearch(A, search_number, 10);
	cout << "Search Result: " << result << endl;
	cout << "number: " << A[result] << endl;
}

