#include <cstdio>
#include <string>
using namespace std;

void score(string s, int n) {
	int a = 0, b = 0, i = 0;
	while (s[i] != 'E') {
		if (s[i] == 'W') {
			a++;
		} else if (s[i] == 'L') {
			b++;
		}
		if (a >= n && a - b >= 2 || b >= n && b - a >= 2) {
			printf("%d:%d\n", a, b);
			a = b = 0;
		}
		i++;
	}
	printf("%d:%d\n", a, b);
}

int main() {
	string s = "";
	char c;
	while (c != 'E') {
		scanf("%c", &c);
		s += c;
	}
	score(s, 11);
	printf("\n");
	score(s, 21);
	return 0;
}