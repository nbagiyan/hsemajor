#include <iostream>
#include <string>
#include <iterator>
using namespace std;

int check(string& str);

int check(string& str) {
	int cnt = 0;
	for (string::iterator it = str.begin(); it != str.end(); ++it) {

		if ((*it == '(') || (*it == '{') || (*it == '[')) {
			cnt++;
		}
		if ((*it == ')') || (*it == '}') || (*it == ']')) {
			cnt--;
		}
		if (cnt < 0) {
			return 0;
		}
	}
	if (cnt > 0) {
		return 0;
	}
	else {
		return 1;
	}
}


int main() {
	string str;
	getline(cin, str);
	if (check(str)) {
		cout << "Brackets' structure is correct";
	}
	else {
		cout << "Brackets' structure is incorrect";
	}
	return 0;
}
