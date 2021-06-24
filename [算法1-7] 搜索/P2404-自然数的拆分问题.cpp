#include <iostream>
#include <string>
using namespace std;

int n, sum;
string s;

void dfs(int start) {
    if (start > n || sum >= n) {
        if (sum == n) cout << s.substr(0, s.length() - 1) << endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (s.length() == 0 || i >= s[s.length() - 2] - '0') {
            sum += i;
            s += i + '0';
            s += '+';
            dfs(start + 1);
            s = s.substr(0, s.length() - 2);
            sum -= i;
        }
    }
}

int main() {
    cin >> n;
    string s;
    dfs(1);
    return 0;
}
