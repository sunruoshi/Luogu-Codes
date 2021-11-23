#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string keys;
        cin >> keys;
        unordered_map<char, int> mp;
        for (size_t i = 0; i < keys.size(); i++) {
            mp.emplace(keys[i], i);
        }
        string word;
        cin >> word;
        int ans = 0;
        for (size_t i = 1; i < word.size(); i++) {
            ans += abs(mp[word[i]] - mp[word[i - 1]]);
        }
        cout << ans << endl;
    }
    return 0;
}
