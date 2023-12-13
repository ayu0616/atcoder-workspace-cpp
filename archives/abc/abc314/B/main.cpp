#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, x;
    cin >> n;
    vvi a(n);
    rep(i, n)
    {
        int c;
        cin >> c;
        a[i].resize(c);
        rep(j, c)
        {
            cin >> a[i][j];
        }
    }
    cin >> x;
    vi ans(n);
    rep(i, n)
    {
        if (find(all(a[i]), x) != a[i].end())
        {
            ans[i] = a[i].size();
        }
        else
        {
            ans[i] = 100;
        }
    }
    int m = *min_element(all(ans));
    vi an;
    rep(i, n)
    {
        if (ans[i] == m && m != 100)
        {
            an.push_back(i + 1);
        }
    }
    cout << an.size() << endl;
    if (an.size())
        cout << an << endl;
}
