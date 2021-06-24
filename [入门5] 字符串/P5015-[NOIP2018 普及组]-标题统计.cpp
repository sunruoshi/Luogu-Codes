#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ' && s[i] != '\n')
			cnt++;
	}
	cout << cnt;
	return 0;
}