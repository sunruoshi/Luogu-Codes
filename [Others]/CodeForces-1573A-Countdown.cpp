#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int res = s[n - 1] - '0';
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] - '0') {
                res += s[i] - '0' + 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}
