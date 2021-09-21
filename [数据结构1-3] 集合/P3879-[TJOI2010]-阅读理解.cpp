#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    unordered_set<string> novals[n + 1];
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        while (num--) {
            string word;
            cin >> word;
            novals[i].insert(word);
        }
    }
    cin >> m;
    while (m--) {
        string word;
        cin >> word;
        for (int i = 1; i <= n; i++) {
            if (novals[i].count(word)) cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
