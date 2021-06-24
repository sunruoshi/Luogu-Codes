#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string key[26] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"};
	int code[26] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 0, 21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9};
	int ans[6] = {0, 0, 0, 0, 0, 0};
	for (int i = 0; i < 6; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 26; j++) {
			if (key[j] == s) {
				ans[i] = code[j];
				break;
			}
		}
	}
	sort(ans, ans + 6);
	string output = "";
	for (int i = 0; i < 6; i++) {
		if (ans[i] != 0) {
			output += ans[i] / 10 + '0';
			output += ans[i] % 10 + '0';
		}
	}
	if (output.length() == 0) {
		cout << "0";
	} else {
		int i = 0;
		while (output[i] == '0') {
			i++;
		}
		cout << output.substr(i, output.length() - i);
	}
	return 0;
}