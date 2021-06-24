#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[100];

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ')') {
			for (int j = i - 1; j >= 0; j--) {
				if (s[j] == '(' and a[j] == 0) {
					a[i] = a[j] = 1;
					break;
				} else if (s[j] == '[' and a[j] == 0)
					break;
			}
		} else if (s[i] == ']') {
			for (int j = i - 1; j >= 0; j--) {
				if (s[j] == '[' and a[j] == 0) {
					a[i] = a[j] = 1;
					break;
				} else if (s[j] == '(' and a[j] == 0)
					break;
			}
		}
	}
	for (int i = 0; i < s.length(); i++) {
		if (a[i] == 0) {
			if (s[i] == '(' || s[i] == ')')
				cout << "()";
			else
				cout << "[]";
		} else
			cout << s[i];
	}
	return 0;
}