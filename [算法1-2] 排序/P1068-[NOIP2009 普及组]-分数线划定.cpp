#include <iostream>
#include <algorithm>
using namespace std;

struct Candidate {
    int id;
    int score;
};

bool cmp(Candidate c1, Candidate c2) {
    if (c1.score != c2.score) return c1.score > c2.score;
    else return c1.id < c2.id;
}

int main() {
    int n, m;
    cin >> n >> m;
    m = m * 150 / 100;
    Candidate c[n];
    for (int i = 0; i < n; i++) {
        Candidate cddt;
        cin >> cddt.id >> cddt.score;
        c[i] = cddt;
    }
    sort(c, c + n, cmp);
    int score = c[m - 1].score, t = 0;
    while (c[t].score >= score) {
        t++;
    }
    cout << score << " " << t << endl;
    for (int i = 0; i < t; i++) {
        cout << c[i].id << " " << c[i].score << endl;
    }
    return 0;
}
