#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        unordered_set<char> st;
        bool flag = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                st.insert(s[i]);
            } else if (!st.count(s[i] + 'a' - 'A')) {
                flag = 0;
                cout << "NO" << endl;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
    }
    return 0;
}
