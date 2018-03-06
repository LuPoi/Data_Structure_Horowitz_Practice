#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1;
	getline(cin, str1);
	int flag = 0;

	for (int i = 0; i <= str1.length(); i++) {
		if (str1[i] != ' ' && isalpha(str1[i]) ) {
			cout << str1[i];
			flag = 0;
		}
		else {
			if (flag == 0) {
				cout << endl;
				flag = 1;
			}
		}
	}
	return 0;
}
