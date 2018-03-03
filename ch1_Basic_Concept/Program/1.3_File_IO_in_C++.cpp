#include <iostream>
#include <fstream>
using namespace std;
//using namespace ios;

int main() {
	ofstream outFile("my.out", ios::out);  // full name>  std::ios::out
	if (!outFile) {
		cerr << "cannot open my.out" << endl; // standard error
		return -1;
	}

	int n=50; float f=20.3;
	outFile << "n: " << n << endl;
	outFile << "f: " << f << endl;

	return 0;
}
