#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int count_over(set<int> &s, int x)
{
    auto it = s.lower_bound(x);
    if (it == s.end())
        return 0;
    return s.size() - distance(s.begin(), it);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<double> c(n), p(n);
    vector<vector<int>> s(n);
    rep(i, n)
    {
        cin >> c[i] >> p[i];
        rep(j, p[i])
        {
            int x;
            cin >> x;
            s[i].push_back(x);
        }
    }
    vector<double> ans(m + 1, 1e9);
    ans[0]=0;
    rep(i, m){
        rep(j, n){
            rep(k, p[j]){
                chmin(ans[min(m, i + s[j][k])], ans[i] + c[j] * p[j]);
            }
        }
    }
    cout << ans[m] << endl;
}
