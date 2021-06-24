#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string removeZero(string s) {
	int i = s.length() - 1;
	while (s[i] == '0') {
		i--;
	}
	return s.substr(0, i + 1);
}

int main() {
	string s;
	cin >> s;
	int typeOfNums = 1, sign = -1, len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] == '.') {
			typeOfNums = 2;
			sign = i;
			break;
		} else if (s[i] == '/') {
			typeOfNums = 3;
			sign = i;
			break;
		} else if (s[i] == '%') {
			typeOfNums = 4;
			break;
		}
	}
	if (typeOfNums == 1 && s != "0") {
		s = removeZero(s);
		reverse(s.begin(), s.end());
	} else if (typeOfNums == 2) {
		string s1 = s.substr(0, sign), s2 = s.substr(sign + 1, len - sign - 1);
		if (s1 != "0") {
			s1 = removeZero(s1);
			reverse(s1.begin(), s1.end());
		}
		if (s2 != "0") {
			reverse(s2.begin(), s2.end());
			s2 = removeZero(s2);
		}
		s = s1 + '.' + s2;
	} else if (typeOfNums == 3) {
		string s1 = s.substr(0, sign), s2 = s.substr(sign + 1, len - sign - 1);
		if (s1 != "0") {
			s1 = removeZero(s1);
			reverse(s1.begin(), s1.end());
		}
		if (s2 != "0") {
			s2 = removeZero(s2);
			reverse(s2.begin(), s2.end());
		}
		s = s1 + '/' + s2;
	} else if (typeOfNums == 4) {
		s = s.substr(0, len - 1);
		if (s != "0") {
			s = removeZero(s);
			reverse(s.begin(), s.end());
		}
		s += '%';
	}
	cout << s;
	return 0;
}