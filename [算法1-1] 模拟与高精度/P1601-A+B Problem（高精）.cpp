#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
	vector<int> res;
	int t = 0;
	for (int i = 0; i < A.size() || i < B.size(); i++) {
		if (i < A.size())
			t += A[i];
		if (i < B.size())
			t += B[i];
		res.push_back(t % 10);
		t /= 10;
	}
	if (t)
		res.push_back(1);
	return res;
}

int main() {
	string s1, s2;
	vector<int> a, b, sum;
	cin >> s1 >> s2;
	for (int i = s1.length() - 1; i >= 0; i--) {
		a.push_back(s1[i] - '0');
	}
	for (int i = s2.length() - 1; i >= 0; i--) {
		b.push_back(s2[i] - '0');
	}
	sum = add(a, b);
	for (int i = sum.size() - 1; i >= 0; i--) {
		cout << sum[i];
	}
	return 0;
}