#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<string> hashSet;
    while (n--) {
        string s;
        cin >> s;
        hashSet.insert(s);
    }
    cout << hashSet.size();
    return 0;
}
