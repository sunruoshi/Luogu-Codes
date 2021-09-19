#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> mp;
    while (n--) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            string name;
            int score;
            cin >> name >> score;
            if (mp.count(name)) {
                mp[name] = score;
            } else {
                mp.emplace(name, score);
            }
            cout << "OK" << endl;
        } else if (opt == 2) {
            string name;
            cin >> name;
            if (mp.count(name)) cout << mp[name] << endl;
            else cout << "Not found" << endl;
        } else if (opt == 3) {
            string name;
            cin >> name;
            if (mp.count(name)) {
                mp.erase(name);
                cout << "Deleted successfully" << endl;
            } else cout << "Not found" << endl;
        } else {
            cout << mp.size() << endl;
        }
    }
    return 0;
}
