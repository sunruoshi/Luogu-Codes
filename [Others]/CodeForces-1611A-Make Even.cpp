#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (!(n & 1)) {
            cout << 0 << endl;
        } else {
            string s = to_string(n);
            if (!((s[0] - '0') & 1)) {
                cout << 1 << endl;
            } else {
                bool flag = 0;
                for (size_t i = 1; i < s.size(); i++) {
                    if (!((s[i] - '0') & 1)) {
                        flag = 1;
                        break;
                    }
                }
                cout << (flag ? 2 : -1) << endl;
            }
        }
    }
    return 0;
}
