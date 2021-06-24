#include <iostream>
#include <string>
using namespace std;

int main() {
	int sum1 = 1, sum2 = 1;
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s1.length(); i++)
		sum1 *= s1[i] - 'A' + 1;
	for (int i = 0; i < s2.length(); i++)
		sum2 *= s2[i] - 'A' + 1;
	if (sum1 % 47 == sum2 % 47)
		cout << "GO";
	else
		cout << "STAY";
	return 0;
}