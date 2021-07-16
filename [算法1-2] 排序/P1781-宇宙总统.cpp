#include <bits/stdc++.h>
using namespace std;

bool isGreater(string s1, string s2) {
    if (s1.size() == s2.size()) return s1 > s2;
    else return s1.size() > s2.size();
}

int main() {
    int n, id;
    string max_t = "0";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (isGreater(s, max_t)) {
            max_t = s;
            id = i + 1;
        }
    }
    cout << id << endl << max_t;
    return 0;
}
