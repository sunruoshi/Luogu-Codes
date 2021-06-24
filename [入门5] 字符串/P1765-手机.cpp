#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, btn[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	int cnt = 0;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			cnt++;
			continue;
		}
		for (int j = 0; j < 8; j++) {
			int found = btn[j].find(s[i]);
			if (found != string::npos) {
				cnt += found + 1;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}