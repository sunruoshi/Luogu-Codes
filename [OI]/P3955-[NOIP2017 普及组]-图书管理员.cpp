#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    int books[n];
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }
    sort(books, books + n);
    while (q--) {
        size_t len;
        string book;
        bool flag = 1;
        cin >> len >> book;
        for (int i = 0; i < n; i++) {
            string cur = to_string(books[i]);
            if (cur.size() < len) continue;
            size_t l = cur.size();
            if (cur.substr(l - len) == book) {
                cout << books[i] << endl;
                flag = 0;
                break;
            }
        }
        if (flag) cout << "-1" << endl;
    }
    return 0;
}
