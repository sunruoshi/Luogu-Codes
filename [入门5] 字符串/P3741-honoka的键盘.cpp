#include <iostream>
#include <string>
using namespace std;

int main () {
	int n, cnt = 1, ans = 0;
	string s;
	cin >> n >> s;
	s = 'A' + s + 'A';
	for (int i = 1; i < n + 1; i++) {
		if (s[i] == 'V') {
			if (s[i + 1] == 'K') {
				ans++;
				s[i] = s[i + 1] = 'A';
			} else if (cnt > 0 && s[i + 1] != 'A' && s[i + 2] != 'K') {
				cnt--;
				ans++;
				s[i] = s[i + 1] = 'A';
			}
		} else if (s[i] == 'K' && cnt > 0 && s[i - 1] != 'A') {
			cnt--;
			ans++;
			s[i] = s[i - 1] = 'A';
		}
	}
	cout << ans;
	return 0;
}