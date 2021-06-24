#include <iostream>
#include <string>
using namespace std;

int main() {
	int start = 0, end = 0, cnt = 0, first = -1;
	string s1, s;
	getline(cin, s1);
	getline(cin, s);
	s += ' ';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}

	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			s1[i] += 32;
	}

	while (end < s.length()) {
		if (s[end] == ' ') {
			string s2 = s.substr(start, end - start);
			if (s1 == s2) {
				cnt++;
				first = first == -1 ? start : first;
			}
			start = end + 1;
		}
		end++;
	}
	if (first == -1)
		cout << -1;
	else
		cout << cnt << ' ' << first;
	return 0;
}