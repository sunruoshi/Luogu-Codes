#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, boy = "boy", girl = "girl";
	int i = 0, b = 0, g = 0;
	cin >> s;
	while (i < s.length()) {
		if (s[i] == '.') {
			i++;
		} else if (boy.find(s[i]) != string::npos) {
			int p = boy.find(s[i]);
			while (boy.find(s[i]) == p) {
				i++;
				p++;
			}
			b++;
		} else {
			int p = girl.find(s[i]);
			while (girl.find(s[i]) == p) {
				i++;
				p++;
			}
			g++;
		}
	}
	cout << b << endl << g;
	return 0;
}