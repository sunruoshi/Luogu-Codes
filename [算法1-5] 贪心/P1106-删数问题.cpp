#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    while (k--) {
        size_t p = 0;
        while (p < s.size() - 1) {
            if (s[p] > s[p + 1]) break;
            p++;
        }
        s.erase(p, 1);
    }
    while (s[0] == '0') {
        s.erase(0, 1);
    }
    cout << (s.size() ? s : "0");
    return 0;
}
