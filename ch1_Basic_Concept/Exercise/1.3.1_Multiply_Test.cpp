#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
	// problem: rand() is not actually random, doent' meet the criterion
	srand(time(NULL));
	int maxInt = std::numeric_limits<int>::max();
	int x = rand();
	int y = rand();
	int result;

	cout << "x is: " << x << endl;
	cout << "y is: " << y << endl;
	if (x*y < x | x*y < y) {
		result = maxInt;
		cout << "result exceed maximum" << endl;
	}
	else {
		result = x*y;
	}

	cout << "result is: " << result << endl;
	return 0;
}
