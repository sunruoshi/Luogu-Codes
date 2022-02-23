#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool flag = 1;
        for (int i = s.size() - 2; i >= 0; i--) {
            int sum = s[i] - '0' + s[i + 1] - '0';
            if (sum >= 10) {
                s[i] = '1';
                s[i + 1] = sum % 10 + '0';
                flag = 0;
                break;
            }
        }
        if (flag) {
            s[1] += s[0] - '0';
            s = s.substr(1);
        }
        cout << s << endl;
    }
    return 0;
}
