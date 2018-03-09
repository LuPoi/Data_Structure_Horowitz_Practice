#include <iostream>
using namespace std;

int r = 0;

void combination(int *a ,int n, const int m) {
	if (n == 0) { // stop criteria
		r += 1;
		cout << "round " << r << ": ";
		for (int i = 0; i < m; i++)
			cout << a[i];
		cout << endl;
		return;
	}
	else {
		// should pass 0 and 1 recursively
		// cout << 1;
		a[n-1] = 1;
		combination(a, n-1, m);

		// cout << 0;
		a[n-1] = 0;
		combination(a, n-1, m);
	}
}

int main() {

//	int n;
//	cout << "intput n: " ;
//	cin >> n ;

	int a[]={1,1,1};
	int n = 3;

	combination(a, n, n);
	return 0;
}
