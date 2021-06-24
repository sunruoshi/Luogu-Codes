#include <iostream>
#include <vector>
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
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	vector<int> prev2 (1, 1), prev1 (1, 1), cur (1, 1);
	for (int i = 2; i <= n; i++) {
		prev2 = prev1;
		prev1 = cur;
		cur = add(prev1, prev2);
	}
	for (int i = cur.size() - 1; i >= 0; i--) {
		cout << cur[i];
	}
	return 0;
}