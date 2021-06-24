#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int d, a, b;
		string s1;
		cin >> d;
		if (d == 1) {
			cin >> s1;
			s += s1;
			cout << s;
		} else if (d == 2) {
			cin >> a >> b;
			s = s.substr(a, b);
			cout << s;
		} else if (d == 3) {
			cin >> a >> s1;
			s.insert(a, s1);
			cout << s;
		} else {
			cin >> s1;
			int found = s.find(s1);
			if (found != string::npos)
				cout << found;
			else
				cout << -1;
		}
		cout << endl;
	}
	return 0;
}