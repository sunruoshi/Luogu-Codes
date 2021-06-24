#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> res;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        res.push_back(t % 10);
        t /= 10;
    }
    if (t)
        res.push_back(1);
    return res;
}

vector<int> mul_int(vector<int> &A, int B)
{
    vector<int> res;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i] * B;
        res.push_back(t % 10);
        t /= 10;
    }
    while (t > 0)
    {
        res.push_back(t % 10);
        t /= 10;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> p (1, 1), s(1, 1);
    for (int i = 2; i <= n; i++)
    {
        p = mul_int(p, i);
        s = add(s, p);
    }
    for (int i = s.size() - 1; i >= 0; i--)
    {
        cout << s[i];
    }
    return 0;
}
