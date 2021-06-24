#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	int m, n, cnt = 0;
	deque<int> dict;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		int word;
		cin >> word;
		if (find(dict.begin(), dict.end(), word) == dict.end()) {
			if (dict.size() == m) {
				dict.pop_front();
			}
			dict.push_back(word);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}