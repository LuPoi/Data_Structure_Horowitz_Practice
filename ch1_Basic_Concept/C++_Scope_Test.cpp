#include <iostream>
using namespace std;

class Cat
{public:
  static int global;
};

int Cat::global=5;
int global = 7;

int main() {

	int global=1;

	cout << global << endl;
	cout << ::global << endl;
	cout << Cat::global << endl;

	return 0;
}
