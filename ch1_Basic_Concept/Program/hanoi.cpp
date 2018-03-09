#include <iostream>
#include <stdlib.h>
using namespace std;

struct top {
	int topA;
	int topB;
	int topC;
	int aj;
	int bj;
	int cj;
};
top get_top(int a[], int b[], int c[], int size) {
	// int topA = 0; int topB = 0; int topC = 0;
	// int aj = 0; int bj = 0; int cj = 0;
	top local_top = {0, 0, 0, 0, 0, 0};
	// get top
	for (int j = 0; j < size; j++) {
		if (a[j] != 0 && local_top.topA == 0) {
			local_top.topA = a[j];
			local_top.aj = j;
		}
		if (b[j] != 0 && local_top.topB == 0) {
			local_top.topB = b[j];
			local_top.bj = j;
		}
		if (c[j] != 0 && local_top.topC == 0) {
			local_top.topC = c[j];
			local_top.cj = j;
		}
	}
	return local_top;
}

void move(top main_top, int a[], int b[], int c[], int n) {
	if (main_top.topB == 0) {
		swap(a[main_top.aj], b[main_top.bj]);
		// cout << "==A_topB: ";
		cout << main_top.topA << endl;
	}
	else if (main_top.topC == 0) {
		swap(a[main_top.aj], c[main_top.cj]);
		// cout << "==A_topC: ";
		cout << main_top.topA << endl;
	}
	else if (main_top.topB < main_top.topC && main_top.topA < main_top.topB) {
		if (main_top.bj != n-1) {
			for (int k = n - 1; k > 0; k--) {
				b[k] = b[k-1];
			}
			b[main_top.bj] = 0;
			swap(a[main_top.aj], b[main_top.bj]);
		}
		else {
			swap(a[main_top.aj], b[main_top.bj-1]);
		}
		// cout << "==A_case3: ";
		cout << main_top.topA << endl;
	}
	else if (main_top.topB > main_top.topC && main_top.topA < main_top.topC) {
		if (main_top.cj != n-1) {
			for (int k = n - 1; k > 0; k--) {
				c[k] = c[k-1];
			}
			c[main_top.cj] = 0;
			swap(a[main_top.aj], c[main_top.cj]);
		}
		else {
			swap(a[main_top.aj], c[main_top.cj-1]);
		}
		// cout << "==A_case4: ";
		cout << main_top.topA << endl;
	}
	else if (main_top.topB > main_top.topC && main_top.topA < main_top.topB) {
		if (main_top.bj != n-1) {
			for (int k = n - 1; k > 0; k--) {
				b[k] = b[k-1];
			}
			b[main_top.bj] = 0;
			swap(a[main_top.aj], b[main_top.bj]);
		}
		else {
			swap(a[main_top.aj], b[main_top.bj-1]);
		}
		// cout << "==A_case3: ";
		cout << main_top.topA << endl;
	}
	else if (main_top.topB < main_top.topC && main_top.topA < main_top.topC) {
		if (main_top.cj != n-1) {
			for (int k = n - 1; k > 0; k--) {
				c[k] = c[k-1];
			}
			c[main_top.cj] = 0;
			swap(a[main_top.aj], c[main_top.cj]);
		}
		else {
			swap(a[main_top.aj], c[main_top.cj-1]);
		}
		// cout << "==A_case4: ";
		cout << main_top.topA << endl;
	}
	else {
	}
}

void print_current_state(int plate[], int size) {
	for (int r = size-1; r >= 0; r--) {
		if (plate[r] != 0)
			cout << plate[r] << " ";
	}
	cout << endl;
}

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

			top main_top = {0, 0, 0, 0, 0, 0};
			main_top = get_top(a, b, c, n);

			cout << "====================" << endl;
			cout << "topA: ";
			print_current_state(a, n);

			cout << "topB: ";
			print_current_state(b, n);

			cout << "topC: ";
			print_current_state(c, n);

			if (i+1 == main_top.topA) {
				move(main_top, a, b, c, n);
			}
			else if (i+1 == main_top.topB) {
				if (main_top.topA == 0) {
					swap(b[main_top.bj], a[main_top.aj]);
					// cout << "==B: ";
					cout << main_top.topB << endl;
				}
				else if (main_top.topC == 0) {
					swap(b[main_top.bj], c[main_top.cj]);
					// cout << "==B: ";
					cout << main_top.topB << endl;
				}
				else if (main_top.topA < main_top.topC && main_top.topB < main_top.topA) {
					if (main_top.aj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							a[k] = a[k-1];
						}
						a[main_top.aj] = 0;
						swap(b[main_top.bj], a[main_top.aj]);
					}
					else {
						swap(b[main_top.bj], a[main_top.aj-1]);
					}
					// cout << "==B: ";
					cout << main_top.topB << endl;
				}
				else if (main_top.topA > main_top.topC && main_top.topB < main_top.topC) {
					if (main_top.cj != n-1) {
						for (int k = n-1; k > 0; k--) {
							c[k] = c[k-1];
						}
						c[main_top.cj] = 0;
						swap(b[main_top.bj], c[main_top.cj]);
					}
					else {
						swap(b[main_top.bj], c[main_top.cj-1]);
					}
					// cout << "==B: ";
					cout << main_top.topB << endl;
				}
				else if (main_top.topA > main_top.topC && main_top.topB < main_top.topA) {
					if (main_top.aj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							a[k] = a[k-1];
						}
						a[main_top.aj] = 0;
						swap(b[main_top.bj], a[main_top.aj]);
					}
					else {
						swap(b[main_top.bj], a[main_top.aj-1]);
					}
					// cout << "==C: ";
					cout << main_top.topC << endl;
				}
				else if (main_top.topA < main_top.topC && main_top.topB < main_top.topC) {
					if (main_top.cj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							c[k] = c[k-1];
						}
						c[main_top.cj] = 0;
						swap(b[main_top.bj], c[main_top.cj]);
					}
					else {
						swap(b[main_top.bj], c[main_top.cj-1]);
					}
					// cout << "==C: ";
					cout << main_top.topC << endl;
				}
				else {
				}
			}
			else if (i+1 == main_top.topC) {
				if (main_top.topA == 0) {
					swap(c[main_top.cj], a[main_top.aj]);
					// cout << "==C: ";
					cout << main_top.topC << endl;
				}
				else if (main_top.topB == 0) {
					swap(c[main_top.cj], b[main_top.bj]);
					// cout << "==C: ";
					cout << main_top.topC << endl;
				}
				else if (main_top.topA < main_top.topB && main_top.topC < main_top.topA) {
					if (main_top.aj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							a[k] = a[k-1];
						}
						a[main_top.aj] = 0;
						swap(c[main_top.cj], a[main_top.aj]);
					}
					else {
						swap(c[main_top.cj], a[main_top.aj-1]);
					}
					// cout << "==C: ";
					cout << main_top.topC << endl;
				}
				else if (main_top.topA > main_top.topB && main_top.topC < main_top.topB) {
					if (main_top.bj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							b[k] = b[k-1];
						}
						b[main_top.bj] = 0;
						swap(c[main_top.cj], b[main_top.bj]);
					}
					else {
						swap(c[main_top.cj], b[main_top.bj-1]);
					}
					// cout << "==C: ";
					cout << main_top.topC << endl;
				}
				else if (main_top.topA > main_top.topB && main_top.topC < main_top.topA) {
					if (main_top.aj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							a[k] = a[k-1];
						}
						a[main_top.aj] = 0;
						swap(c[main_top.cj], a[main_top.aj]);
					}
					else {
						swap(c[main_top.cj], a[main_top.aj-1]);
					}
					// cout << "==C: ";
					cout << main_top.topC << endl;
				}
				else if (main_top.topA < main_top.topB && main_top.topC < main_top.topB) {
					if (main_top.bj != n-1) {
						for (int k = n - 1; k > 0; k--) {
							b[k] = b[k-1];
						}
						b[main_top.bj] = 0;
						swap(c[main_top.cj], b[main_top.bj]);
					}
					else {
						swap(c[main_top.cj], b[main_top.bj-1]);
					}
					// cout << "==C: ";
					cout << main_top.topC << endl;
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
	cout << "====================" << endl;
	cout << "topA: ";
	print_current_state(a, n);

	cout << "topB: ";
	print_current_state(b, n);

	cout << "topC: ";
	print_current_state(c, n);
}

int main(){
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
