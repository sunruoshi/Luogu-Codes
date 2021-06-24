#include <iostream>
#include <string>
using namespace std;

int main() {
	int freq[26], max = 0;
	for (int i = 0; i < 26; i++)
		freq[i] = 0;
	for (int i = 0; i < 4; i++) {
		string s;
		getline(cin, s);
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= 'A' && s[j] <= 'Z') {
				freq[s[j] - 'A']++;
				max = freq[s[j] - 'A'] > max ? freq[s[j] - 'A'] : max;
			}
		}
	}
	while (max > 0) {
		string line = "";
		for (int i = 0; i < 26; i++) {
			if (freq[i] >= max) {
				line += "* ";
			} else {
				line += "  ";
			}
		}
		cout << line.substr(0, line.length() - 1) << endl;
		max--;
	}
	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
	return 0;
}