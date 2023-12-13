#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    vi c(n);
    rep(i, n)
    {
        int x;
        cin >> x;
        c[i] = x - 1;
    }
    vector<deque<int>> q(m);
    rep(i, n)
    {
        q[c[i]].push_back(i);
    }
    rep(i, m)
    {
        int x = q[i].back();
        q[i].pop_back();
        q[i].push_front(x);
    }
    rep(i, n)
    {
        cout << s[q[c[i]].front()];
        q[c[i]].pop_front();
    }
    cout << endl;
}
