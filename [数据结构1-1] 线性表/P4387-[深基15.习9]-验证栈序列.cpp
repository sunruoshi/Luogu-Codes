#include <iostream>
#include <stack>
using namespace std;

int main() {
	int q, n;
	cin >> q;
	while (q--) {
		stack<int> myStack;
		cin >> n;
		int pushed[n], poped[n], pos = 0;
		for (int i = 0; i < n; i++) {
			cin >> pushed[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> poped[i];
		}
		for (int i = 0; i < n; i++) {
			myStack.push(pushed[i]);
			while (myStack.top() == poped[pos]) {
				myStack.pop();
				pos++;
				if (myStack.empty())
					break;
			}
		}
		if (myStack.empty()) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}