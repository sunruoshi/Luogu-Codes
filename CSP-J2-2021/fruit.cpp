#include <iostream>
#include <deque>
#include <list>
#include <cstring>
using namespace std;

int main() {
    freopen("fruit.in", "r", stdin);
    freopen("fruit.out", "w", stdout);

    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n + 2];
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    list<deque<int>> fruits;
    int l = 1, r = 1;
    while (r <= n) {
        deque<int> q;
        while (a[r] == a[l]) {
            q.push_back(r++);
        }
        fruits.push_back(q);
        l = r;
    }
    while (fruits.size()) {
        auto it = fruits.begin();
        while (it != fruits.end()) {
            if ((*it).size()) {
                cout << (*it).front() << ' ';
                (*it).pop_front();
                it++;
            } else {
                while (it != fruits.end() && (*it).empty()) {
                    it = fruits.erase(it);
                    if (it != fruits.begin() && it != fruits.end()) {
                        auto Next = it--;
                        (*it).insert((*it).end(), (*Next).begin(), (*Next).end());
                        it = fruits.erase(Next);
                    }
                }
            }
        }
        cout << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
