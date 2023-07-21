#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    rep(i, n)
    {
        int v;
        cin >> v;
        v--;
        a[i] = v;
        s.insert(v);
    }
    set<int> prev = s;
    s.clear();
    for (auto x : prev)
    {
        s.insert(a[x]);
    }
    int cnt = 2;
    while (prev.size() != s.size())
    {
        prev = s;
        s.clear();
        for (auto x : prev)
        {
            s.insert(a[x]);
        }
        cnt++;
    }
    cout << cnt << endl;
}
