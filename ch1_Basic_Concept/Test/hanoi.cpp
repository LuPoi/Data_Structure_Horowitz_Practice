#include <iostream>
#include <stdlib.h>
using namespace std;

void hanoi(int n, char A, char B, char C) {
	int a[n-1]; int b[n-1]; int c[n-1];
	int flag = 0; int sumA = 0;
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
		b[i] = 0;
		c[i] = 0;
		sumA = a[i] + sumA;
	}

	while ( flag == 0 ) {
		int sumB = 0; int sumC = 0;

		for (int i = 0; i < n; i++) {
			// cout << "current i: " << i << endl;
			int topA = 0; int topB = 0; int topC = 0;
			int aj = 0; int bj = 0; int cj = 0;
			// get top
			for (int j = 0; j < n; j++) {
				if (a[j] != 0 && topA == 0) {
					topA = a[j];
					aj = j;
				}
				if (b[j] != 0 && topB == 0) {
					topB = b[j];
					bj = j;
				}
				if (c[j] != 0 && topC == 0) {
					topC = c[j];
					cj = j;
				}
			}

			cout << "====================" << endl;
			cout << "topA: ";
			for (int r = n-1; r >= 0; r--) {
				if (a[r] != 0)
					cout << a[r] << " ";
			}
			cout << endl;

			cout << "topB: ";
			for (int r = n-1; r >= 0; r--) {
				if (b[r] != 0)
					cout << b[r] << " ";
			}
			cout << endl;

			cout << "topC: ";
			for (int r = n-1; r >= 0; r--) {
				if (c[r] != 0)
					cout << c[r] << " ";
			}
			cout << endl;

			// cout << "topA: " << topA << endl;
			// cout << "topB: " << topB << endl;
			// cout << "topC: " << topC << endl;

			if (i+1 == topA) {
				if (topB == 0) {
					swap(a[aj], b[bj]);
					// cout << "==A_topB: ";
					cout << topA << endl;
				}
				else if (topC == 0) {
					swap(a[aj], c[cj]);
					// cout << "==A_topC: ";
					cout << topA << endl;
				}
				else if (topB < topC && topA < topB) {
					if (bj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							b[k] = b[k-1];
						}
						b[bj] = 0;
						swap(a[aj], b[bj]);
					}
					else {
						swap(a[aj], b[bj-1]);
					}
					// cout << "==A_case3: ";
					cout << topA << endl;
				}
				else if (topB > topC && topA < topC) {
					if (cj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							c[k] = c[k-1];
						}
						c[cj] = 0;
						swap(a[aj], c[cj]);
					}
					else {
						swap(a[aj], c[cj-1]);
					}
					// cout << "==A_case4: ";
					cout << topA << endl;
				}
				else if (topB > topC && topA < topB) {
					if (bj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							b[k] = b[k-1];
						}
						b[bj] = 0;
						swap(a[aj], b[bj]);
					}
					else {
						swap(a[aj], b[bj-1]);
					}
					// cout << "==A_case3: ";
					cout << topA << endl;
				}
				else if (topB < topC && topA < topC) {
					if (cj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							c[k] = c[k-1];
						}
						c[cj] = 0;
						swap(a[aj], c[cj]);
					}
					else {
						swap(a[aj], c[cj-1]);
					}
					// cout << "==A_case4: ";
					cout << topA << endl;
				}
				else {
				}
			}
			else if (i+1 == topB) {
				if (topA == 0) {
					swap(b[bj], a[aj]);
					// cout << "==B: ";
					cout << topB << endl;
				}
				else if (topC == 0) {
					swap(b[bj], c[cj]);
					// cout << "==B: ";
					cout << topB << endl;
				}
				else if (topA < topC && topB < topA) {
					if (aj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							a[k] = a[k-1];
						}
						a[aj] = 0;
						swap(b[bj], a[aj]);
					}
					else {
						swap(b[bj], a[aj-1]);
					}
					// cout << "==B: ";
					cout << topB << endl;
				}
				else if (topA > topC && topB < topC) {
					if (cj != n-1) {
						for (int k = n-1; k > 0; k--) {
							c[k] = c[k-1];
						}
						c[cj] = 0;
						swap(b[bj], c[cj]);
					}
					else {
						swap(b[bj], c[cj-1]);
					}
					// cout << "==B: ";
					cout << topB << endl;
				}
				else if (topA > topC && topB < topA) {
					if (aj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							a[k] = a[k-1];
						}
						a[aj] = 0;
						swap(b[bj], a[aj]);
					}
					else {
						swap(b[bj], a[aj-1]);
					}
					// cout << "==C: ";
					cout << topC << endl;
				}
				else if (topA < topC && topB < topC) {
					if (cj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							c[k] = c[k-1];
						}
						c[cj] = 0;
						swap(b[bj], c[cj]);
					}
					else {
						swap(b[bj], c[cj-1]);
					}
					// cout << "==C: ";
					cout << topC << endl;
				}
				else {
				}
			}
			else if (i+1 == topC) {
				if (topA == 0) {
					swap(c[cj], a[aj]);
					// cout << "==C: ";
					cout << topC << endl;
				}
				else if (topB == 0) {
					swap(c[cj], b[bj]);
					// cout << "==C: ";
					cout << topC << endl;
				}
				else if (topA < topB && topC < topA) {
					if (aj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							a[k] = a[k-1];
						}
						a[aj] = 0;
						swap(c[cj], a[aj]);
					}
					else {
						swap(c[cj], a[aj-1]);
					}
					// cout << "==C: ";
					cout << topC << endl;
				}
				else if (topA > topB && topC < topB) {
					if (bj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							b[k] = b[k-1];
						}
						b[bj] = 0;
						swap(c[cj], b[bj]);
					}
					else {
						swap(c[cj], b[bj-1]);
					}
					// cout << "==C: ";
					cout << topC << endl;
				}
				else if (topA > topB && topC < topA) {
					if (aj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							a[k] = a[k-1];
						}
						a[aj] = 0;
						swap(c[cj], a[aj]);
					}
					else {
						swap(c[cj], a[aj-1]);
					}
					// cout << "==C: ";
					cout << topC << endl;
				}
				else if (topA < topB && topC < topB) {
					if (bj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							b[k] = b[k-1];
						}
						b[bj] = 0;
						swap(c[cj], b[bj]);
					}
					else {
						swap(c[cj], b[bj-1]);
					}
					// cout << "==C: ";
					cout << topC << endl;
				}
				else {
				}
			}
			else {
			}
		}

		for (int i = 0; i < n; i++) {
			sumB = b[i] + sumB;
			sumC = c[i] + sumC;
		}
		if ( abs(sumB - sumA) == 1 | abs(sumC - sumA) == 1 ) {
			flag = 1;
			cout << "1" << endl;
		}
	}
}

int main(){
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
