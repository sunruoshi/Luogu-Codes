#include <iostream>
#include <string>
using namespace std;

int main() {
	char a = '0', b = '0', c = '0';
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i += 5) {
		string s1 = s.substr(i, 5);
		if (s1[0] == 'a') {
			if (s1[3] >= '0' && s1[3] <= '9') {
				a = s1[3];
			} else {
				if (s1[3] == 'b')
					a = b;
				else if (s1[3] == 'c')
					a = c;
			}
		} else if (s1[0] == 'b') {
			if (s1[3] >= '0' && s1[3] <= '9') {
				b = s1[3];
			} else {
				if (s1[3] == 'a')
					b = a;
				else if (s1[3] == 'c')
					b = c;
			}
		} else if (s1[0] == 'c') {
			if (s1[3] >= '0' && s1[3] <= '9') {
				c = s1[3];
			} else {
				if (s1[3] == 'a')
					c = a;
				else if (s1[3] == 'b')
					c = b;
			}
		}
	}
	cout << a << ' ' << b << ' ' << c;
	return 0;
}